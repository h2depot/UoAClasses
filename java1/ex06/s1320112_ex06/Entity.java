abstract class Entity{
  protected String name;
  protected int size;

  public Entity(String name){this.name = name;}

  public String getName(){ return name; }
  public void rename(String name){ this.name = name; }
  public abstract int getSize();
}
