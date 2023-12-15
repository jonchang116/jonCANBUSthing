import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CANBUSdecode {
    public static void main(String[] args) {
        String logFilePath = "D:/canbus hsit";

        try (BufferedReader br = new BufferedReader(new FileReader(logFilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                decodeCanMessage(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void decodeCanMessage(String logEntry) {
        // Define the regular expression pattern for extracting relevant information
        String regex = "\\(([^)]+)\\) (\\S+) (\\S+)";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(logEntry);

        if (matcher.find()) {
            String timestamp = matcher.group(1);
            String interfaceName = matcher.group(2);
            String hexData = matcher.group(3);

            // Assuming 8 bytes of hexadecimal data
            byte[] rawData = hexStringToByteArray(hexData.substring(1));

            // Perform decoding logic based on your specifications
            // Example: print raw data
            System.out.println("Timestamp: " + timestamp);
            System.out.println("Interface: " + interfaceName);
            System.out.println("Hex Data: " + hexData);
            System.out.println("Decoded Data: " + byteArrayToHexString(rawData));
            System.out.println();
        }
    }

    private static byte[] hexStringToByteArray(String hexString) {
        int len = hexString.length();
        byte[] data = new byte[len / 2];

        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(hexString.charAt(i), 16) << 4)
                    + Character.digit(hexString.charAt(i + 1), 16));
        }

        return data;
    }

    private static String byteArrayToHexString(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02X ", b));
        }
        return sb.toString().trim();
    }
}
