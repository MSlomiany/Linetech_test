### Zadanie 2
Zakładam znane długości ramion robota, jeden stopień swobody na ramię oraz dokładną znajomość położenia silników (enkoder, serwo etc.)
Co daje w przybliżeniu taki schemat
![Robotarm](https://github.com/MSlomiany/Linetech_test/blob/master/zadanie2/robot.png)
* Wektor A:
  * Początek w 0,0,0
  * Koniec w:
    * yA = A * cos alfa
    * zA = A * sin alfa
* Wektor B:
  * Początek w końcówce wektora A
  * Koniec w:
    * yB = B * cos (beta - alfa)
    * zB = B * sin (beta - alfa)
Analogicznie wektor C, jego długość jest podana poprzez wynik pomiaru długości

Punkt K wektora OK obliczamy dodając kolejno punkty składowych wektorów.
Aby obliczyć |OK| należy obliczyć pod pierwiastkiem yK^2+zK^2 (punkt O ma wspołrzędne 0,0,0).


