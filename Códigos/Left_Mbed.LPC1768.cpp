// Left MBED - legs: L1 R2 L3

#include "mbed.h"

// Serial port
Serial  toradex(USBTX, USBRX);  // tx, rx
DigitalOut led(LED1);

// PWM pins
PwmOut  coxa1(p21);
PwmOut  perna1(p22);

PwmOut  coxa2(p23);
PwmOut  perna2(p24);

PwmOut  coxa3(p25);
PwmOut  perna3(p26);

// Functions and states
void set_period();
void standard();
void walk();

int main(){
    
    toradex.baud(9600);
    int is_walking = 0;
    
    set_period();
    
    while(1) {
        
        if (toradex.readable()) {
            if (is_walking == 0){
                led = 1;
                is_walking = 1;
            }
            else {
                led = 0;
                is_walking = 0;
            }
        }
        else standard();
                
        if (is_walking == 1) walk();
        else standard();
        
    }
    
}

void set_period(){
    
    coxa1.period(0.020);
    perna1.period(0.020);
    
    coxa2.period(0.020);
    perna2.period(0.020);
    
    coxa3.period(0.020);
    perna3.period(0.020);
    
}

void standard(){
    
    coxa1.pulsewidth(0.0013);
    perna1.pulsewidth(0.0017);
    
    coxa2.pulsewidth(0.0014);
    perna2.pulsewidth(0.0010);
    
    coxa3.pulsewidth(0.0017);
    perna3.pulsewidth(0.0020);

}

void walk(){
    
    for(float i=0.0; i<=0.0003; i=i+0.00001){ //1
        
        coxa1.pulsewidth(0.0013+i);
        perna1.pulsewidth(0.0011+2*i);
        
        coxa2.pulsewidth(0.0014-i);
        perna2.pulsewidth(0.0004+2*i);
        
        coxa3.pulsewidth(0.0017+i);
        perna3.pulsewidth(0.0026-2*i);
        
        wait_ms(10);
        
    }
    
     for(float i=0.0; i<=0.0003; i=i+0.00001){ //2
        
        coxa1.pulsewidth(0.0016-i);
        perna1.pulsewidth(0.0017);
        
        coxa2.pulsewidth(0.0011+i);
        perna2.pulsewidth(0.0010);
        
        coxa3.pulsewidth(0.0020-i);
        perna3.pulsewidth(0.0020);
        
        wait_ms(10);
        
    }
    
    for(float i=0.0; i<=0.0003; i=i+0.00001){ //3
        
        coxa1.pulsewidth(0.0013-i);
        perna1.pulsewidth(0.0017);
        
        coxa2.pulsewidth(0.0014+i);
        perna2.pulsewidth(0.0010);
        
        coxa3.pulsewidth(0.0017-i);
        perna3.pulsewidth(0.0020);
        
        wait_ms(10);
        
    }
    
     for(float i=0.0; i<=0.0003; i=i+0.00001){  //4
        
        coxa1.pulsewidth(0.0010+i);
        perna1.pulsewidth(0.0017-2*i);
        
        coxa2.pulsewidth(0.0017-i);
        perna2.pulsewidth(0.0010-2*i);
        
        coxa3.pulsewidth(0.0014+i);
        perna3.pulsewidth(0.0020+2*i);
        
        wait_ms(10);
        
    }

}
