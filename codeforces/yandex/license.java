import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class license {
    public static void main(String args[]) {
        String license_numbers[] = {"KZ473BUA02", "A849BTA", "UZ473BUA02", "473BUA02", "KZ777ZZZ02"};
        Pattern patternOld = Pattern.compile("^(A[0-9]{3}[A-Za-z]{3})");
        Pattern patternNew = Pattern.compile("^(KZ[0-9]{3}[A-Za-z]{3}02)");
        for(String license : license_numbers) {
            if(patternNew.matcher(license).matches() || patternOld.matcher(license).matches()) {
                System.out.println("Yes, This number was registered in Almaty: " + license);
            } else {
                System.out.println("No, Not found "  + license);
            }
        }
    }
}