public class Directory extends Entity{
//private String name;
//private File[] fileList = new File[100];
//private Directory[] directoryList = new Directory[100]; private int numberOfFile = 0;
//private int numberOfDirectory = 0;
private Entity[] entityList = new Entity[200];
private int numberOfEntity = 0;
public Directory(String name){ 
    super(name);
    size = 0; 
}
//public String getName(){ return name; }
//public void rename(String name){this.name = name;}
/*public int getSize(){
    int total = 0;
    for ( int i = 0; i < numberOfFile; i++ ){
        total += fileList[i].getSize();
    }
    for ( int i = 0; i < numberOfDirectory; i++ ){
        total += directoryList[i].getSize();
    }
    return total;
}*/
public int getSize(){
    int total = 0;
    for ( int i = 0; i < numberOfEntity; i++ ){
        total += entityList[i].getSize();
    }
    return total;
}
/*public void add(File file){
    fileList[numberOfFile++] = file;
}
public void add(Directory directory){ directoryList[numberOfDirectory++] = directory; }*/
public void add(Entity entity){ entityList[numberOfEntity++] = entity; }
public void display(){
    for ( int i = 0; i < numberOfEntity; i++ ){System.out.print(entityList[i].getName() + " "); }
    System.out.println(); System.out.println(this.getSize() + " bytes");
} 
}