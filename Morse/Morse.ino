/*
  Morse
  Converts a given string (hard coded) into a Morse code (on
  PIN 13) using the Morse alphabet and the durations standard.

  2015-12-27 miqwit
 */

String alphabet[123];

// Set the Morse alphabet and declare PIN 13 as output
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  // Define morse alphabet. Indexed by ascii code
  alphabet[97] = ".-";    // a
  alphabet[98] = "-...";  // b
  alphabet[99] = "-.-.";  // c
  alphabet[100] = "-..";  // d
  alphabet[101] = ".";    // e
  alphabet[102] = "..-."; // f
  alphabet[103] = "--.";  // g
  alphabet[104] = "...."; // h
  alphabet[105] = "..";   // i
  alphabet[106] = ".---"; // j
  alphabet[107] = "-.-";  // k
  alphabet[108] = ".-.."; // l
  alphabet[109] = "--";   // m
  alphabet[110] = "-.";   // n
  alphabet[111] = "---";  // o
  alphabet[112] = ".--."; // p
  alphabet[113] = "--.-"; // q
  alphabet[114] = ".-.";  // r
  alphabet[115] = "...";  // s
  alphabet[116] = "-";    // t
  alphabet[117] = "..-";  // u
  alphabet[118] = "...-"; // v
  alphabet[119] = ".--";  // w
  alphabet[120] = "-..-"; // x
  alphabet[121] = "-.--"; // y
  alphabet[122] = "--.."; // z
}

// Will loop the morse code forever
void loop() {
  String text = "morse code will never die "; // This is the text that will be translated to Morse
  text.toLowerCase();
  int len = text.length();

  // Browse each letter of text and call displayMorseLetter on it
  char letter;
  for (int idx = 0; idx < len; idx++) {
    letter = text.charAt(idx);
    displayMorseLetter(letter);
  }
}

// Display morse letter with light
void displayMorseLetter(char letter) {
  int ti_duration = 50;
  int taah_duration = 3 * ti_duration;
  int inside_letter_duration = ti_duration;
  int between_letters = taah_duration;
  int between_words = 7 * ti_duration;

  if (letter == ' ') {
    delay(between_words);
    return;
  }
  
  String letterMorse = alphabet[(int) letter];
  int len = letterMorse.length();

  char titaah;
  for (int idx = 0; idx < len; idx++) {
    char titaah = letterMorse.charAt(idx);

    int light_duration;
    switch (titaah) {
      case '.':
        light_duration = ti_duration;
        break;
        
      case '-':
        light_duration = taah_duration;
        break;
    }

    // PIN 13 on
    digitalWrite(13, HIGH);
    delay(light_duration);
      
    // PIN 13 off after light_duration
    digitalWrite(13, LOW);
    delay(inside_letter_duration);
  }

  delay(between_letters);
}

