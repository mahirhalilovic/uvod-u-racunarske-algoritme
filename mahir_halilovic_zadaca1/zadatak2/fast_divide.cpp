int fast_divide(int a, int b) {
  if(a < b) return 0;

  int i = 1;
  while(i * b <= a)
    i *= 2;

  i /= 2;

  return i + fast_divide(a - i * b, b);
}

// Napisati funkciju fast_divide koja uz pomoć rekurzije određuje količnik dva cijela
// broja metodom egipatskog dijeljenja. Ova metoda je slična metodi egipatskog
// množenja koja je rađena na vježbama.
// Mala pomoć: tražiti najveći stepen broja dva, koji kad se pomnoži sa djeliteljem,
// bude manji od djeljenika, te ga oduzeti.
