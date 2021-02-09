public class Student extends People {
    String name;
    int age;
    int score;

    void ChangeStudent(Student s) {
        s.age = 17;
        s.name = "shabi";
        s.score = 59;
    }

    public static void main(String[] args) {
        Student s = new Student();
        s.speek();
    }
}
