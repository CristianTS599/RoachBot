/* 
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note frequency period timeHigh
 * c         261 Hz         3830 1915 
 * d         294 Hz         3400 1700 
 * e         329 Hz         3038 1519 
 * f         349 Hz         2864 1432 
 * g         392 Hz         2550 1275 
 * a         440 Hz         2272 1136 
 * b         493 Hz         2028 1014
 * C        523 Hz        1912 956
 * D         588 Hz         1700 850 
 * E         658 Hz         1519 760 
 * F         698 Hz         1432 716 
 * G         784 Hz         1275 638 
 * A         880 Hz         1136 568
 * B         986 Hz         1014 507
 */
//LIGHTS
 int LEDpins[]={2,3,4,5,6,7,8,9};
 int Timer = 300;
 int speakerPin = 10; //pin to use to drive speaker
            // next line lists notes we want to be able to play
 char names[] = {'c','d','e','f','g','a','b','C','D','E','F','G','A','B'}; 
 int rangeOfNotes = 14; //number of notes available in the above array
//next line lists values corresponding to note names in names[] array
 int tones[] ={1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 850, 760, 716, 638, 568, 507};
 int length = 19;  // the number of notes and rests I want to play in my song
 char notes[] = "CEAC EAEBEAB EGECE eba"; // notes to play. A space represents a rest
/*next line lists how long to play each note or rest. 
 it has to be a double rather than an int to allow for decimals*/
 double beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; 
 int tempo = 300; //how long one beat is in milliseconds
//ccggaagffeeddc .
//ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc 
//gEDCggEDCaaFEDbGAGFDE,1,1,1,1,4,1,1,1,1,4,1,1,1,1,3,1,1,1,1,1,4,4 
 void setup(){
   pinMode(speakerPin, OUTPUT);
   pinMode(LEDpins[0], OUTPUT);
   pinMode(LEDpins[1], OUTPUT);
   pinMode(LEDpins[2], OUTPUT);
   pinMode(LEDpins[3], OUTPUT);
   pinMode(LEDpins[4], OUTPUT);
   pinMode(LEDpins[5], OUTPUT);
   pinMode(LEDpins[6], OUTPUT);
   pinMode(LEDpins[7], OUTPUT);
 }
 
 void loop()
{  
  for (int i = 0; i < length; i++){//for each note in the character array (string)
    for (int pins = 2; pins < 10; pins++)
    digitalWrite(pins,HIGH);
    delay(beats[i]*tempo);
    for (int pins = 2; pins < 10; pins++)
    digitalWrite(pins,LOW);
     if (notes[i] == ' '){
     //if the character is a space, do the following line.
       delay(beats[i] * tempo); //rest (there is a pause in the music)
     }      else { //otherwise (if the character is not a space), do the following line. 
       playNote(notes[i], beats[i] * tempo);/*play the note notes[i] for
       the ammount of time beats[i] * tempo, by using the playNote function defined below*/
     }
     //delay(tempo/2);//if you want to include a pause between notes, but throws rhythm off.
   } 
   /*for (int i = 0; i < length; i++){//for each note in the character array (string)
    if(notes[i]=='C')
    digitalWrite(LEDpins[2],HIGH);*/
 }


       
 void playNote(char note, int duration){//plays the note "note" for the time "duration"  
   //play the tone corresponding to the note name
   for (int i = 0; i < rangeOfNotes; i++){
     if (names[i] == note){
       playTone(tones[i], duration);
     }
   }
 }
    
 void playTone(int tone, int duration){
   for (long i = 0; i < duration *1000L; i += tone * 2){
     digitalWrite(speakerPin, LOW);
     delayMicroseconds(tone);
     digitalWrite(speakerPin, HIGH);
     delayMicroseconds(tone);
   }
 }
