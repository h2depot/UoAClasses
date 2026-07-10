class Int{
  int x;
  static final int INT_MAX = 1024;

  Int(int x){
    setValue(x);
  }

  Int add(Int a) { return new Int(getValue() + a.x); }
  Int mul(Int a) { return new Int(getValue() * a.x); }
  void setValue(int a) { x = a; }
  int getValue() { return x; }

  @Override
  public String toString() { return "" + x; }
}