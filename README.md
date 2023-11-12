# CH32V003-pcm-player
Plays an pcm audio file on the CH32V003 microcontroller

Materials needed:
* Piezo buzzer or speaker on the D5 pin , Piezo needs an membrane attached to it to make louder sounds
* An CH32V003 microcontroller (I used the J4M6 version thats 8 pinned)

When programming the CH32V003, remove the piezo/speaker or it'll refuse to program, and probably do minichlink -ua on it to wipe the program (also remove speaker before doing this)

I programmed the ch32v003 using https://github.com/AlexanderMandera/arduino-wch32v003 and an minichlink programmer from https://github.com/cnlohr/ch32v003fun

Also before converting the audio file, import it into audacity and find the Effect option and go to the Volume and compression option and click the compressor and compress it till it no longer sounds very quiet (I just click the apply option, don't really mess with the settings) or what'll happen is the audio will be quiet and unheardable. And export the audio as an WAV and select 16000hz sampling rate and encode it as 8 bit unsigned pcm. Also trim parts of the sound file that are silent to save space or don't.

Maximum duration of the audio file is 900 miliseconds less or more, found out when i had to start deleting some values
