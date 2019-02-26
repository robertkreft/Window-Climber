#include <Servo.h>

Servo pio_prz;
Servo zeb_pio;
Servo zeb_pra;
Servo boc_pra;
Servo zeb_lew;
Servo boc_lew;
Servo tyl;
Servo zeb_poz;

void setup() {
  pio_prz.attach(13);
  zeb_pio.attach(12);
  zeb_pra.attach(11);
  boc_pra.attach(10);
  zeb_lew.attach(9);
  tyl.attach(7);
  boc_lew.attach(8);
  zeb_poz.attach(6);
}

int i=0;
char ok='l';

void loop() {
  if(i==0)
  {
    polowiczne();
    delay(5000);
    poczatkowa();
    i++;
  }
  
  if (analogRead(A0)>80&&analogRead(A0)<100)
  do_przodu();

  else if (analogRead(A0)>800&&analogRead(A0)<850)
  do_tylu();
  
  else if (analogRead(A0)>500&&analogRead(A0)<530)
  w_lewo();

  else if (analogRead(A0)>700&&analogRead(A0)<740)
  w_prawo();
}

void polowiczne()
{
  pio_prz.write(70);
  zeb_pio.write(75);
  zeb_pra.write(98);
  zeb_lew.write(87);
  boc_pra.write(85);
  boc_lew.write(85);
  tyl.detach();
  zeb_poz.write(87);
}

void poczatkowa()
{
  boc_lew.attach(8);
  pio_prz.write(180); //odczepianie przyssawek
  boc_pra.write(0);
  boc_lew.write(180);
  tyl.write(0);
  delay(800);
  pio_prz.detach(); //polowiczne dla 180
  boc_pra.detach();
  boc_lew.detach();
  tyl.detach();
  delay(500);
  
  zeb_pio.write(0); //zebatka pionowa do przodu
  delay(1900);
  zeb_pio.detach();
  delay(500);

  zeb_pra.write(0); //zebatki na ramionach do gory
  zeb_lew.write(180);
  delay(1100);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(1000);

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(180); //przyssawki boczne przyczepiaja sie
  boc_lew.write(0);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();

  zeb_poz.detach();
  ok='p';
}

void do_przodu()
{
  zeb_pio.attach(12);
  zeb_pio.write(180); //zebatka pionowa do tylu
  delay(2100);
  zeb_pio.detach();
  delay(500);

  zeb_pra.attach(11);
  zeb_lew.attach(9);
  zeb_pra.write(180); //zebatki na ramionach w dol 
  zeb_lew.write(0);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(500);//<-----

  pio_prz.attach(13);
  tyl.attach(7);
  pio_prz.write(0); //przyssawki pionowe przyczepiają się
  tyl.write(180);
  delay(900);
  pio_prz.detach();
  tyl.detach();
  delay(500);

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(0); //przyssawki boczne odczepiają się
  boc_lew.write(180);
  delay(2000);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  zeb_pio.attach(12);
  zeb_pio.write(0); //zębatka pionowa do przodu
  delay(1900);
  zeb_pio.detach();

  zeb_pra.attach(11);
  zeb_lew.attach(9);
  zeb_pra.write(0); //zębatki na ramionach do góry
  zeb_lew.write(180);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(180); //przyssawki boczne przyczepiają się
  boc_lew.write(0);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  pio_prz.attach(13);
  tyl.attach(7);
  pio_prz.write(180); //przyssawki pionowe odczepiają się
  tyl.write(0);
  delay(1300);
  pio_prz.detach();
  tyl.detach();
  delay(500);
}

void do_tylu()
{
  zeb_pra.attach(11);
  zeb_lew.attach(9);
  
  zeb_pra.write(180); //zębatki na ramionach w dół
  zeb_lew.write(0);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(500);//<------

  pio_prz.attach(13);
  tyl.attach(7);
  pio_prz.write(0); //przyssawki pionowe się przyczepiają
  tyl.write(180);
  delay(900);
  pio_prz.detach();
  tyl.detach();
  delay(500);

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(0); //przyssawki boczne się odczepiają
  boc_lew.write(180);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  zeb_pio.attach(12);
  zeb_pio.write(180); //zębatka pinowa do tyłu
  delay(1900);
  zeb_pio.detach();
  
  zeb_pra.attach(11);
  zeb_lew.attach(9);

  zeb_pra.write(0); //zębatki na ramionach do góry
  zeb_lew.write(180);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(500);//<------

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(180); //przyssawki boczne przyczepiają się
  boc_lew.write(0);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  pio_prz.attach(13);
  tyl.attach(7);
  pio_prz.write(180); //przyssawki pionowe odczepiają się
  tyl.write(0);
  delay(900);
  pio_prz.detach();
  tyl.detach();
  delay(500);

  zeb_pio.attach(12);
  zeb_pio.write(0); //zębatka pionowa do przodu
  delay(1900);
  zeb_pio.detach();
}

void w_prawo()
{


  if(ok=='l'){
    zeb_poz.attach(6);
    zeb_poz.write(180);
    delay(2000);
    zeb_poz.detach();
  }
  zeb_pra.attach(11);
  zeb_lew.attach(9);
  
  
  
  zeb_pra.write(180); //zębatki na ramionach w dół
  zeb_lew.write(0);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(500);//<------

pio_prz.attach(13);
tyl.attach(7);
  pio_prz.write(0); //przyssawki pionowe przyczepiają się
  tyl.write(180);
  delay(900);
  pio_prz.write(70);
  tyl.detach();
  delay(500);

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(0); //przyssawki boczne odczepiają się
  boc_lew.write(180);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  zeb_poz.attach(6);

  zeb_poz.write(0); //zębatka pozioma w górę
  delay(2000);
  zeb_poz.detach();

  zeb_pra.attach(11);
  zeb_lew.attach(9);

  zeb_pra.write(0); //zębatki na bokach w górę
  zeb_lew.write(180);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();
  delay(500);//<------

  boc_lew.attach(8);
  boc_pra.attach(10);
  boc_pra.write(180); //przyssawki boczne przyczepiają się
  boc_lew.write(0);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  tyl.attach(7);
  pio_prz.write(180); //przyssawki pionowe odczepiają się
  tyl.write(0);
  delay(900);
  pio_prz.write(97);
  tyl.detach();
  delay(500);

  zeb_poz.attach(6);

  zeb_poz.write(180); //zębatka pozioma na środek
  delay(2000);
  zeb_poz.detach();
  ok='p';
}

void w_lewo()
{


  if(ok=='p'){
    zeb_poz.attach(6);
    zeb_poz.write(0);
    delay(2000);
    zeb_poz.detach();
  }
  zeb_pra.attach(11);
  zeb_lew.attach(9);

  
 

  zeb_pra.write(180); //zębatki na ramionach w dół
  zeb_lew.write(0);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();

  pio_prz.attach(13);
  tyl.attach(7);
  pio_prz.write(0); //przyssawki pionowe przyczepiają się
  tyl.write(180);
  delay(900);
  pio_prz.write(70);
  tyl.detach();
  delay(500);

  boc_pra.attach(10);
  boc_lew.attach(8);
  boc_pra.write(0); //przyssawki boczne odczepiają się
  boc_lew.write(180);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  zeb_poz.attach(6);

  zeb_poz.write(180); //zębatka pozioma w dół
  delay(2000);
  zeb_poz.detach();

  zeb_pra.attach(11);
  zeb_lew.attach(9);

  zeb_pra.write(0); //zębatki na bokach w górę
  zeb_lew.write(180);
  delay(900);
  zeb_pra.detach();
  zeb_lew.detach();

  boc_lew.attach(8);
  boc_pra.attach(10);
  boc_pra.write(180); //przyssawki boczne przyczepiają się
  boc_lew.write(0);
  delay(1500);
  boc_pra.detach();
  boc_lew.detach();
  delay(500);

  tyl.attach(7);
  pio_prz.write(180); //przyssawki pionowe odczepiają się
  tyl.write(0);
  delay(900);
  pio_prz.write(97);
  tyl.detach();
  delay(500);

  zeb_poz.attach(6);

  zeb_poz.write(0); //zębatka pozioma na środek
  delay(2000);
  zeb_poz.detach();
  ok='l';
}

