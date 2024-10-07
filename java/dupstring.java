public class dupstring {
    public static void main(String[] args) {
        String str = "vvce mysuru";
        char[] chararray = str.toCharArray();
        System.out.println("The string is: " + str);
        System.out.println("String length: " + str.length());
        System.out.println("Duplicate characters in the string: ");

        for (int i = 0; i < str.length(); i++) {
            for (int j = i+1; j < str.length(); j++) { 
                if (str.charAt(i) == str.charAt(j)) {
                    System.out.println(chararray[j] + "");
                    break; 
                }
            }
        }
    }
}
