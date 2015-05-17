/**************************************************************************/
/*!
    @file     l298n_motor_driver_example.c
    @author   A. Khan
    @section LICENSE
    Software License Agreement (BSD License)
    Copyright (c) 2015, Art of Circuits (artofcircuits.com)
    All rights reserved.
    
      This is an example code for L298N Module
      http://artofcircuits.com/product/l298n-motor-driver-board

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
/**************************************************************************/

const int ENA = 11;
const int IN1 = 9;
const int IN2 = 8;

const int ENB = 6;
const int IN3 = 4;
const int IN4 = 5;
 
void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
}
 
void loop()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

 
  for(byte i = 0; i < 256; i++) //Accelerate
  {
    analogWrite(ENA, i);
    analogWrite(ENB, i);    
    delay(100);
  }
 
  for(byte j = 5; j > 0; j--) //Hold top speed
  {
    delay(1000);
  }
 
  digitalWrite (IN1, LOW); //Switch direction
  digitalWrite(IN2, HIGH);

  digitalWrite (IN3, LOW); //Switch direction
  digitalWrite(IN4, HIGH);

  for(byte h = 0; h < 256; h++) //Accelerate
  {
    analogWrite(ENA, h);
    analogWrite(ENB, h);    
    delay(100);
  }
 
    for(byte u = 5; u > 0; u--) //Hold top speed
  {
    delay(1000);
  }
}
