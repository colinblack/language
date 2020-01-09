//引用类型缺省值null

public class RefAndNull {
    public static void main(String[] args){
        Student[] s = new Student[10];
        for(int i = 0; i < s.length; i++){
            System.out.println(s[i]);
        }

        for(int i = 0; i < s.length; i++){
            if(i %2 == 0){
                s[i] = new Student();
            }

        }

        for(int i = 0; i < s.length; i++){
            System.out.println(s[i]);
        }

        Student s1 = new Student();
        s1.ChangeStudent(s1);
        System.out.println(s1.name);

    }


}
