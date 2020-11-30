

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class GestiuneTemp extends JFrame{
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	static JLabel titlu = new JLabel();
	static JLabel background;
    static JPanel p1,p2,mainPanel;
   
    public static void initiereComponente() {
    	//ImageIcon icon = new ImageIcon("fisiere/poza.jpg");
    	//background = new JLabel("",icon,JLabel.CENTER);
    	//background.setBounds(0,0,400,200);
    	ArduinoSerial arduino = new ArduinoSerial("/dev/cu.wchusbserialfa130");
    	
    	Thread t = new Thread() {
    		@Override
    		public void run() {
    			arduino.initialize();
    			
    			while(true) {
    				
    				    String a = arduino.read();
    				    titlu.setText(a);
    			
    			}
    		}
    	};
    	t.start();

    	
    	p1=new JPanel();
    	
    	p1.add(titlu);  
    	
    	mainPanel=new JPanel();
    	mainPanel.add(p1);
   
    	
    	
    	
    }
    public GestiuneTemp() {
    	
    	
    	
    	super("Temperatura & Umiditate");
    	
    	super.setDefaultCloseOperation(EXIT_ON_CLOSE);
    	super.setVisible(true);
    	//super.setLocation(200,500);
    	super.setLocationRelativeTo(null);
    	super.setPreferredSize(new Dimension(400, 100));
        //setLayout(new FlowLayout(FlowLayout.LEFT));
    	initiereComponente();
    	
    	
    
    	BoxLayout layout = new BoxLayout(mainPanel, BoxLayout.PAGE_AXIS); 
        GestiuneTemp.mainPanel.setLayout(layout);
        add(mainPanel);
        super.pack();
    }
    
	
}
