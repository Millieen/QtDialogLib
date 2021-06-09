public class Test {

    public static void main(String args[])
    {
        System.setProperty("jna.debug_load", "true");
        int ret = 0;
        ret = CDialogLib.INSTANCE.Initialize(null);
        System.out.println("Initialize() return " + ret);
        ret = CDialogLib.INSTANCE.ShowMessageDialog("Title from Java", "中文信息");
        System.out.println("ShowMessageDialog(\"Title from Java\", \"中文信息\") return " + ret);
        ret = CDialogLib.INSTANCE.Finalize();
        System.out.println("Finalize() return " + ret);
    }
}
