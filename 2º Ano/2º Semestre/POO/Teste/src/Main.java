import javax.swing.*;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.HyperlinkListener;

public class Main {
    public static void main(String[] args) {
        JFrame myFrame = new JFrame("JEditorPane Test");
        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myFrame.setSize(400, 200);
        JEditorPane myPane = new JEditorPane();
        myPane.setContentType("text/html");
        myPane.setText("<html><body><a href=\"https://vivaoabuso.pt:2/1-0\">ola</a></body></html>");
        myFrame.setContentPane(myPane);
        myPane.setEditable(false);
        myPane.addHyperlinkListener(new HyperlinkListener() {
            public void hyperlinkUpdate(HyperlinkEvent e) {
                if (e.getEventType() == HyperlinkEvent.EventType.ACTIVATED)
                    myPane.setText("<html><body><button style=\"background: blue;color: red;\">Sleeping is necessary for a healthy body."
                        + " But sleeping in unnecessary times may spoil our health, wealth and studies."
                        + " Doctors advise that the sleeping at improper timings may lead for obesity during the students days.</button><input type='text'></body></html>");
            }
        });

        myFrame.setVisible(true);
    }
}