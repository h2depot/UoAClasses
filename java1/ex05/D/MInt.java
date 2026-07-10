class MInt extends Int{
  static final int MOD = 107;

  MInt(int x){
    super(x);
  }

  @Override
  MInt add(Int a) { return new MInt((getValue() + a.x) % MOD); }

  @Override
  MInt mul(Int a) { return new MInt((getValue() * a.x) % MOD); }

  @Override
  public String toString() { return "" + getValue(); }
}