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

  // Define morse alphabet
  alphabet[97] = ".-";
  alphabet[98] = "-...";
  alphabet[99] = "-.-.";
  alphabet[100] = "-..";
  alphabet[101] = ".";
  alphabet[102] = "..-.";
  alphabet[103] = "--.";
  alphabet[104] = "....";
  alphabet[105] = "..";
  alphabet[106] = ".---";
  alphabet[107] = "-.-";
  alphabet[108] = ".-..";
  alphabet[109] = "--";
  alphabet[110] = "-.";
  alphabet[111] = "---";
  alphabet[112] = ".--.";
  alphabet[113] = "--.-";
  alphabet[114] = ".-.";
  alphabet[115] = "...";
  alphabet[116] = "-";
  alphabet[117] = "..-";
  alphabet[118] = "...-";
  alphabet[119] = ".--";
  alphabet[120] = "-..-";
  alphabet[121] = "-.--";
  alphabet[122] = "--..";
}

// Will loop the morse code forever
void loop() {
  String text = "morse code will never die ";
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

