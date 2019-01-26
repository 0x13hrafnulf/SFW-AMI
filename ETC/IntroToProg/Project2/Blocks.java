import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Blocks extends Figure {
	private int w;
	private int h;
	private int value;
	private Font font = new Font("Serif", Font.BOLD, 50);

	public Blocks(int x, int y, int w, int h, int value) {
		super(x, y);
		this.w = w;
		this.h = h;
		this.value = value;
	}

	@Override
	public void draw(Graphics g) {
		Graphics2D gBold = (Graphics2D) g;
		g.setColor(new Color(166, 0, 0));
		g.fillRect(x, y, w, h);
		gBold.setStroke(new BasicStroke(6));
		gBold.setColor(Color.BLACK);
		gBold.drawRect(x, y, w, h);

		
		gBold.setFont(this.font);
		FontMetrics fm = gBold.getFontMetrics();
		int stringAsc = fm.getAscent();
		int stringWidth = fm.stringWidth(String.valueOf(value));
		gBold.drawString(String.valueOf(value == 0?"": value), x+w/2 - stringWidth /2, y + h - stringAsc/2);

	}

	@Override
	public boolean contains(int x, int y) {
		boolean bx = this.x <= x && x <= this.x + this.w;
		boolean by = this.y <= y && y <= this.y + this.h;
		return bx && by;
	}
}
