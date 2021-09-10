
#include <Keypad.h>  //install keypad library by Mark Stanley and Alexander Brevig

/*circuit: pin 2 corresopinds to f2 side on keypad. pin 10 is connected to extreme left of the keypad. other pins in between follow each other*/

const byte ROWS = 5; //5 rows
const byte COLS = 4; //4 columns
//character array for string (more than one character)
char* specialKeys[] ={
            "F1",  "F2", "#", "*",
            "1",  "2", "3", "UP",
            "4",  "5", "6", "DOWN",
            "7",  "8", "9", "ESC",
            "LEFT",  "0", "RIGHT", "ENTER"  
                    };

//character array for chars                    
char specialKeysID[] = {
        'A',  'B', '#', '*',
        '1',  '2', '3', 'C',
        '4',  '5', '6', 'D',
        '7',  '8', '9', 'E',
        'F',  '0', 'G', 'H'
      };                    

//populating the keys multidimensional array
char keys[ROWS][COLS] = {
{specialKeysID[0],  specialKeysID[1], specialKeysID[2], specialKeysID[3]},
{specialKeysID[4],  specialKeysID[5], specialKeysID[6], specialKeysID[7]},
{specialKeysID[8],  specialKeysID[9], specialKeysID[10], specialKeysID[11]},
{specialKeysID[12],  specialKeysID[13], specialKeysID[14], specialKeysID[15]},
{specialKeysID[16],  specialKeysID[17], specialKeysID[18], specialKeysID[19]}
};


byte rowPins[ROWS] = {2,3,4,5,6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {10,9,8,7}; //connect to the column pinouts of the kpd


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() { 
  Serial.begin(9600);  
}


void loop() {
  
  char key = keypad.getKey();
    // just print the pressed key (string eg f1, ent, esc)    
   if (key){
    Serial.print("Key: ");
    
    Serial.println(getKey(key));
    
    //To print single characters
    //Serial.println(key);
  } 
}  // End loop


//getKey function to change print "string type characters"
char* getKey(char *k)
{
//Robojax.com 5x4 keypad detecting string value
for(int i=0; i<20; i++)
 {
    if(specialKeysID[i] ==k) return specialKeys[i];
  }
 
}//getKey


 
