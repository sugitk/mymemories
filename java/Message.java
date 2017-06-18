/* Message.java */

// parameters:
// message

// last modified 96/06/11

import java.awt.*;
import java.applet.Applet;

public class Message extends Applet implements Runnable
{
	public Thread slideThread;
	private int x;
	private String message;
	private int messageWidth=0;
	private Font font;

	public void init()
	{
		Font font = new Font("TimesRoman",Font.PLAIN,24);
		message = getParameter("message");
		messageWidth = getFontMetrics(font).stringWidth(message);
		resize(512,36);
		x = size().width;
	}

	public void update(Graphics g)
	{
		g.drawImage(makeImage(),0,0,null);
	}

	public Image makeImage()
	{
		Image im = createImage(size().width,size().height);
		Graphics g = im.getGraphics();
		g.setColor(Color.blue); //背景
		g.fillRect(0,0,size().width,size().height);
		g.setColor(Color.yellow); //文字
		g.setFont(new Font("TimesRoman",Font.PLAIN,24));
		g.drawString(message,x,size().height/2);
		return im;
	}

	public void start()
	{
		slideThread = new Thread(this);
		slideThread.start();
	}

	public void stop()
	{
		slideThread.stop();
	}

	public void run()
	{
		while(slideThread.isAlive())
		{
			try
			{
				Thread.sleep(100);
			}
			catch(InterruptedException e)
			{}
			repaint();
			x = x-10;
			if(x + messageWidth < 0) x = size().width;
		}
	}
}
