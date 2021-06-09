import com.sun.jna.Library;
import com.sun.jna.Native;

public interface CDialogLib extends Library {
    CDialogLib INSTANCE = Native.load("DialogLib", CDialogLib.class);
    int Initialize(String resourcefile);
    int Finalize();

    int ShowMessageDialog(String title, String message);
}
