import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.util.*;

public class Shuffle_GUI extends JFrame {
	int scores = 0;
	CanvasPanel panel = new CanvasPanel();
	JPanel controlPanel = new JPanel();
	JButton restart = new JButton("Start");
	JButton random = new JButton("Random");
	JTextField score = new JTextField(String.valueOf(scores), 6);
	Puzzle puz = new Puzzle();
	Figure[][] blocks = new Figure[puz.n][puz.n];
	Figure selectedFigure = null;

	Shuffle_GUI() {
		setLayout(new BorderLayout());

		add(panel);
		panel.setFocusable(true);
		panel.setBackground(Color.LIGHT_GRAY);

		score.setHorizontalAlignment(JTextField.CENTER);

		controlPanel.add(restart);
		controlPanel.add(score);
		controlPanel.add(random);
		add(controlPanel, BorderLayout.SOUTH);
		controlPanel.setBackground(Color.GRAY);
		panel.addKeyListener(new PanelKeyListener());
		panel.addMouseListener(new PanelMouseListener());

		restart.setFocusable(false);
		random.setFocusable(false);
		restart.addActionListener(new RestartButtonListener());
		random.addActionListener(new RandomButtonListener());
	}

	public static void main(String[] args) {
		run();
	}

	class CanvasPanel extends JPanel {
		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			int dw = getWidth() / puz.n;
			int dh = getHeight() / puz.n;
			Graphics2D gBold = (Graphics2D) g;
			for (int i = 0; i < puz.n; ++i) {
				for (int j = 0; j < puz.n; ++j) {
					gBold.setStroke(new BasicStroke(6));
					gBold.setColor(Color.BLACK);
					gBold.drawRect(dw * j, dh * i, dw, dh);
				}
			}
			for (int i = 0; i < puz.n; ++i) {
				for (int j = 0; j < puz.n; ++j) {
					blocks[i][j] = new Blocks(dw * j, dh * i, dw, dh, puz.puzzle[i][j]);
					blocks[i][j].draw(g);
				}
			}
		}

	}

	class PanelKeyListener extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {
			int temp = puz.blankPos(puz.puzzle);
			if (e.getKeyCode() == KeyEvent.VK_UP || e.getKeyCode() == KeyEvent.VK_W) {
				puz.move("W");
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_DOWN || e.getKeyCode() == KeyEvent.VK_S) {
				puz.move("S");
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_RIGHT || e.getKeyCode() == KeyEvent.VK_D) {
				puz.move("D");
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_LEFT || e.getKeyCode() == KeyEvent.VK_A) {
				puz.move("A");
				repaint();
			} else if (e.getKeyCode() == KeyEvent.VK_F1) {
				JOptionPane.showMessageDialog(null, "Programming 2, Project 2\nBektur Umarbaev (AUCA)");
			}
			if (puz.blankPos(puz.puzzle) != temp)
				++scores;
			score.setText(String.valueOf(scores));
			if (scores > 0 && puz.gameWin()) {
				JOptionPane.showMessageDialog(null, "GRATZZ!!! YOU WON!!!");
			}
		}

	}

	class PanelMouseListener extends MouseAdapter {

		@Override
		public void mouseClicked(MouseEvent e) {
			for (int i = 0; i < puz.n; ++i) {
				for (int j = 0; j < puz.n; ++j) {
					if (blocks[i][j].contains(e.getX(), e.getY())) {
						if(puz.blankNeighbor(i, j)){
							int temp = puz.blankPos(puz.puzzle);
							puz.move(i,j);
							repaint();				
							if (puz.blankPos(puz.puzzle) != temp)
								++scores;
							score.setText(String.valueOf(scores));
							if (scores > 0 && puz.gameWin()) {
								JOptionPane.showMessageDialog(null, "GRATZZ!!! YOU WON!!!");
							}
						}
					}
				}
			}
		}

	}

	class RestartButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			puz.start();
			boolean continueInput = true;
			do {
				try{
					int moves = Integer.parseInt(JOptionPane.showInputDialog("Number of moves to shuffle:", "0"));
					puz.shuffle(moves);
					scores = 0;
					score.setText(String.valueOf(scores));
					repaint();
					continueInput = false;
			} catch (NumberFormatException E) {
				JOptionPane.showMessageDialog(null, "Wrong input. Try Again.", "Error",JOptionPane.ERROR_MESSAGE);
			}
			} while (continueInput);
		}

	}

	class RandomButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			puz.shuffleRnd();
			scores = 0;
			score.setText(String.valueOf(scores));
			repaint();
		}

	}

	static void run() {
		Shuffle_GUI frame = new Shuffle_GUI();
		frame.setTitle("Puzzle 15");
		frame.setResizable(false);
		frame.setSize(400, 400);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
