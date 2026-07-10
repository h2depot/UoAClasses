public class File extends Entity{
    //private String name;
    //private int size;
    public File(String name, int size){
       super(name);
       this.size = size;
    }
    //public String getName(){ return name; }
    //public void rename(String name){this.name = name; }
    public int getSize(){ return size; }
}