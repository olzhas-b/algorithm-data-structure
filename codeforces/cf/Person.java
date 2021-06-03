public class Person {
    private int age;
    private String name;
    Person() {
        age = 0;
        name = "Nick Name";
    }
    Person(String name, int age) {
        this.age = age;
        this.name = name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        if(age < 0 || age > 90) {
            System.out.println("It's impossible, please change your age");
        }
        else {
            this.age = age;
        }
    }
    public String to_String() {
        return this.name + " " + String.valueOf(this.age);
    }
}