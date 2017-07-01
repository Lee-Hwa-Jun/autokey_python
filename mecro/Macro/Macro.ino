const int numRows= 4;
const int numCols= 4;
 
int pinRows[numRows] = {2, 3, 4, 5};
int pinCols[numCols] = {6, 7, 8, 9};
int set[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
void setup() {
    Serial.begin(9600);    // init Serial communication

    pinMode(13,OUTPUT);
    // initialize row pins as INPUT_PULLUP
    for(int i=0; i<numRows; i++) {
        pinMode(pinRows[i], INPUT_PULLUP);
    }
    
    // initialize column pins as OUTPUT
    for(int j=0; j<numCols; j++) {
        pinMode(pinCols[j], OUTPUT);
        digitalWrite(pinCols[j], HIGH);    // set initial output as HIGH
    }
}

void loop() {
    // Check input
    for(int j=0; j<numCols; j++) {
        digitalWrite(pinCols[j], LOW);    // set as LOW to check button press
        for(int i=0; i<numRows; i++) {
            if( digitalRead(pinRows[i]) == LOW ) {    // check input. LOW is pressed
              digitalWrite(13,HIGH);
              Serial.println(set[j][i]);
            }
        }
        digitalWrite(pinCols[j], HIGH);    // set as default (HIGH)
    }
    delay(200);
    digitalWrite(13,LOW);
}
