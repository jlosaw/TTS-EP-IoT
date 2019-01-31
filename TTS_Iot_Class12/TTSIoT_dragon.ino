// This #include statement was automatically added by the Particle IDE.
#include <SoftPWM.h>


// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>

#define PIN_SERVO_FLAME_1 D0
#define PIN_SERVO_FLAME_2 D1
#define PIN_SERVO_FLAME_3 D2

#define PIN_IGNITE D3

//D0 - used for servo 3
//D1 - used for servo 2
//D2 - used for servo 1

//D3 - used for high voltage // 1 - ON, 0 - off




//==== SERVO POSITION VALUES
#define SERVO_FLAME_POS_OPEN 30
#define SERVO_FLAME_POS_SHUT 130

#define DELAY_BEFORE_SHUT 600
#define SERVO_CHANNEL_FLAME 1

//=== Values for TowerPro SG90 small servos; adjust if needed
#define COUNT_LOW 1638
#define COUNT_HIGH 7864
#define SERVO_TIMER_WIDTH 16

// 
#define PWM_LOW                0
#define PWM_TOP                255

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//char auth[] = "e0b10f70add841ebb4002e8f072e9ccd";
char auth[] = "e44f229eb6214f62ba919d225c72c637";



bool flaming = false;
uint32_t flamingStartTime = millis();

BLYNK_WRITE(V2) // Breath Fire 
{
    flaming = true;
    flamingStartTime = millis();
}

BLYNK_WRITE(V1) 
{
    int x = param[0].asInt();
    int y = param[1].asInt();

    // Do something with x and y
    Serial.print("X = ");
    Serial.print(x);
    Serial.print("; Y = ");
    Serial.println(y);

        
    /*
    1. Get X and Y from the Joystick, do whatever scaling and calibrating you need to do based on your hardware.
    2. Invert X
    3. Calculate R+L (Call it V): V =(100-ABS(X)) * (Y/100) + Y
    4. Calculate R-L (Call it W): W= (100-ABS(Y)) * (X/100) + X
    5. Calculate R: R = (V+W) /2
    6. Calculate L: L= (V-W)/2
    7. Do any scaling on R and L your hardware may require.
    8. Send those values to your Robot.
            Go back to 1.
    */
    int16_t xValue, yValue;
    xValue = map(x, 0, 1023, -70, 70);
    yValue = map(y, 0, 1023, -100, 100);

    //        xValue = (-xValue);

    double V = (100 - abs(xValue)) * (yValue / 100) + yValue;
    double W = (100 - abs(yValue)) * (xValue / 100) + xValue;
    int16_t R = (V + W) / 2;
    int16_t L = (V - W) / 2;
    
    motorAPlay(L);
    motorBPlay(R);

    //  motorAPlay(yValue);
    //  motorBPlay(yValue);

}

Servo servo1;
Servo servo2;
Servo servo3;

uint8_t currServoPos = SERVO_FLAME_POS_SHUT;

#define MOTORBAPWM D4
#define MOTORBBPWM D5
#define MOTORAAPWM D6
#define MOTORABPWM D7





void setup()
{
    Serial.begin();
    Serial.println(F("testing started..."));

    // 
    pinMode(PIN_IGNITE, OUTPUT);
    digitalWrite(PIN_IGNITE, LOW);

    pinMode(MOTORBAPWM, OUTPUT);
    pinMode(MOTORBBPWM, OUTPUT);
    pinMode(MOTORAAPWM, OUTPUT);
    pinMode(MOTORABPWM, OUTPUT);


    pinMode(PIN_SERVO_FLAME_1, OUTPUT);
    pinMode(PIN_SERVO_FLAME_2, OUTPUT);
    pinMode(PIN_SERVO_FLAME_3, OUTPUT);


    servo1.attach(PIN_SERVO_FLAME_1);
    servo2.attach(PIN_SERVO_FLAME_2);
    servo3.attach(PIN_SERVO_FLAME_3);

    servo1.write(SERVO_FLAME_POS_SHUT - 20);
    servo1.write(SERVO_FLAME_POS_SHUT - 20);
    servo1.write(SERVO_FLAME_POS_SHUT - 20);
    delay(400);
    servo1.write(SERVO_FLAME_POS_SHUT);
    servo2.write(SERVO_FLAME_POS_SHUT);
    servo3.write(SERVO_FLAME_POS_SHUT);
    
    delay(2500);
    
    //
    Blynk.begin(auth);

    SoftPWMBegin();

    //test motors
    motorAPlay(100);
    motorBPlay(100);
    delay(500);
    motorAPlay(0);
    motorBPlay(0);
    delay(500);
    motorAPlay(-100);
    motorBPlay(-100);
    delay(500);
    motorAPlay(0);
    motorBPlay(0);
    delay(200);
        digitalWrite(PIN_IGNITE, HIGH); // Start Igniter before opening servo
    delay(50);
        digitalWrite(PIN_IGNITE, LOW); // Start Igniter before opening servo


    
//    flaming = true;
//    flamingStartTime = millis();

}


void loop()
{
    // servo control part
    if (flaming)
    {
        const uint32_t PREFLAMINGTIME = 150;
        const uint32_t HALFFLAMINGTIME = 150;
        const uint32_t FULLFLAMETIME = 1000;
        // 
        digitalWrite(PIN_IGNITE, HIGH); // Start Igniter before opening servo
    
        // check elapsed time in flaming step
        uint32_t flamingTime = millis() - flamingStartTime;
        if (flamingTime < PREFLAMINGTIME) // 150ms, shut down position
            currServoPos = SERVO_FLAME_POS_SHUT;
        else if (flamingTime < (PREFLAMINGTIME + HALFFLAMINGTIME)) // 150ms, shut down position
            currServoPos = (SERVO_FLAME_POS_OPEN + SERVO_FLAME_POS_SHUT) / 2;
        else if (flamingTime < (PREFLAMINGTIME + HALFFLAMINGTIME + FULLFLAMETIME))
            currServoPos = SERVO_FLAME_POS_OPEN;
        else
            flaming = false;
    }
    else
    {
        currServoPos = SERVO_FLAME_POS_SHUT;
        digitalWrite(PIN_IGNITE, LOW); // Start Igniter before opening servo
    }

    static uint32_t lastServoTime = millis();
    if (millis() - lastServoTime >= SERVO_TIMER_WIDTH)
    {
        servo1.write(currServoPos);
        servo2.write(currServoPos);
        servo3.write(currServoPos);
        lastServoTime = millis();
    }
    Blynk.run();
}

void motorAPlay(int8_t speed)
{
    uint8_t value = 0;
    
    digitalWrite(MOTORABPWM, HIGH);
    digitalWrite(MOTORAAPWM, HIGH);
    

    if (speed < 3)
    {
        value = map(abs(speed), 0, 100, PWM_LOW, PWM_TOP);
        SoftPWMSet(MOTORABPWM, PWM_LOW);
        SoftPWMSet(MOTORAAPWM, value);
    }
    else if (speed > 3)
    {
        value = map(abs(speed), 0, 100, PWM_LOW, PWM_TOP);
        //    digitalWrite(PIN_MOTOR_A_A, HIGH);
        SoftPWMSet(MOTORAAPWM, PWM_LOW);
        SoftPWMSet(MOTORABPWM, value);
    }
    else
    {
        value = 3;
        SoftPWMSet(MOTORAAPWM, value);
        SoftPWMSet(MOTORABPWM, value);
    }

}

void motorBPlay(int8_t speed)
{
    uint8_t value = 0;
    if (speed < 3)
    {
        value = map(abs(speed), 0, 100, PWM_LOW, PWM_TOP);
        SoftPWMSet(MOTORBAPWM, value);
        SoftPWMSet(MOTORBBPWM, PWM_LOW);
        // digitalWrite(PIN_MOTOR_B_A, HIGH);
        // ledcWrite(MOTORAPWM, value);    
    
    }
    else if (speed > 3)
    {
        value = map(abs(speed), 0, 100, PWM_LOW, PWM_TOP);
        SoftPWMSet(MOTORBAPWM, PWM_LOW);
        SoftPWMSet(MOTORBBPWM, value);
        //    digitalWrite(PIN_MOTOR_B_B, HIGH);
    }
    else
    {
        value = 0;
        SoftPWMSet(MOTORBAPWM, value);
        SoftPWMSet(MOTORBBPWM, value);
    }
}
