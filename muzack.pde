import ddf.minim.analysis.*;
import ddf.minim.*;
import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
Minim minim;  
AudioPlayer song;
FFT fftLin;
FFT fftLog;

float spectrumScale = 4;
Serial myPort;
int click = 0;

void setup()
{
  size(512, 480);

  minim = new Minim(this);
  song = minim.loadFile("tardistakeoff.mp3", 1024);
  
  fftLin = new FFT( song.bufferSize(), song.sampleRate() );
  fftLin.linAverages(8);
    
  rectMode(CORNERS);
  
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  background(0);
  

  fftLin.forward( song.mix );
  int w = int( width/fftLin.avgSize() );
  System.out.print(Math.round(fftLin.getAvg(0)));  
  float out = map(Math.round(fftLin.getAvg(0)), 0, 30, 0, 16);
  int intOut = (int) out;
  myPort.write(intOut);    

  rect(w, height, w+512, height - fftLin.getAvg(0)*10);

  System.out.println();
}

void mouseClicked(){
 if( click == 0 ) {
   song.close();
   song = minim.loadFile("tardistakeoff.mp3", 1024);
   song.play();
   click = 1;
 } else {
   song.close();
   song = minim.loadFile("hal9000clip1.wav", 1024);
   song.play();
   click = 0;
 }
}



  
