package ihm;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.BorderLayout;
import javax.swing.JTextField;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JToolBar;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import java.awt.Color;
import java.awt.Font;
import java.awt.Window.Type;
import javax.swing.JButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.SystemColor;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Interface {

	private JFrame frmCalculatrice;
	private JLabel ecran = new JLabel();
	private JLabel label_npi_field = new JLabel("");
	private JLabel label_resultat_field = new JLabel("");
	private JButton button = new JButton("0");
	private JButton button_1 = new JButton("=");
	private JButton button_2 = new JButton(",");
	private JButton button_3 = new JButton("1");
	private JButton btnEn = new JButton("En");
	private JButton button_4 = new JButton("2");
	private JButton button_5 = new JButton("3");
	private JButton button_6 = new JButton("(");
	private JButton button_7 = new JButton("4");
	private JButton button_8 = new JButton("5");
	private JButton button_9 = new JButton("6");
	private JButton button_10 = new JButton(")");
	private JButton button_11 = new JButton("7");
	private JButton button_12 = new JButton("8");
	private JButton button_13 = new JButton("9");
	private JButton btnC = new JButton("C");
	private JButton button_14 = new JButton("+");
	private JButton button_15 = new JButton("-");
	private JButton btnX = new JButton("*");
	private JButton button_16 = new JButton("/");
	private JButton button_17 = new JButton("(-)");
	private JButton btnIm = new JButton("Im");
	private JButton btnSv = new JButton("Sv");
	private JTextField textField;
	JButton btnY = new JButton("y");
	private String expression_final="";
	
	/**********************GETTERS & SETTERS*********************************/
	public JLabel getEcran() {
		return ecran;
	}

	public void setEcran(JLabel ecran) {
		this.ecran = ecran;
	}

	public JLabel getLabel_npi_field() {
		return label_npi_field;
	}

	public void setLabel_npi_field(JLabel label_npi_field) {
		this.label_npi_field = label_npi_field;
	}

	public JLabel getLabel_resultat_field() {
		return label_resultat_field;
	}

	public void setLabel_resultat_field(JLabel label_resultat_field) {
		this.label_resultat_field = label_resultat_field;
	}

	public JButton getButton() {
		return button;
	}

	public void setButton(JButton button) {
		this.button = button;
	}

	public JButton getButton_1() {
		return button_1;
	}

	public void setButton_1(JButton button_1) {
		this.button_1 = button_1;
	}

	public JButton getButton_2() {
		return button_2;
	}

	public void setButton_2(JButton button_2) {
		this.button_2 = button_2;
	}

	public JButton getButton_3() {
		return button_3;
	}

	public void setButton_3(JButton button_3) {
		this.button_3 = button_3;
	}

	public JButton getBtnEn() {
		return btnEn;
	}

	public void setBtnEn(JButton btnEn) {
		this.btnEn = btnEn;
	}

	public JButton getButton_4() {
		return button_4;
	}

	public void setButton_4(JButton button_4) {
		this.button_4 = button_4;
	}

	public JButton getButton_5() {
		return button_5;
	}

	public void setButton_5(JButton button_5) {
		this.button_5 = button_5;
	}

	public JButton getButton_6() {
		return button_6;
	}

	public void setButton_6(JButton button_6) {
		this.button_6 = button_6;
	}

	public JButton getButton_7() {
		return button_7;
	}

	public void setButton_7(JButton button_7) {
		this.button_7 = button_7;
	}

	public JButton getButton_8() {
		return button_8;
	}

	public void setButton_8(JButton button_8) {
		this.button_8 = button_8;
	}

	public JButton getButton_9() {
		return button_9;
	}

	public void setButton_9(JButton button_9) {
		this.button_9 = button_9;
	}

	public JButton getButton_10() {
		return button_10;
	}

	public void setButton_10(JButton button_10) {
		this.button_10 = button_10;
	}

	public JButton getButton_11() {
		return button_11;
	}

	public void setButton_11(JButton button_11) {
		this.button_11 = button_11;
	}

	public JButton getButton_12() {
		return button_12;
	}

	public void setButton_12(JButton button_12) {
		this.button_12 = button_12;
	}

	public JButton getButton_13() {
		return button_13;
	}

	public void setButton_13(JButton button_13) {
		this.button_13 = button_13;
	}

	public JButton getBtnC() {
		return btnC;
	}

	public void setBtnC(JButton btnC) {
		this.btnC = btnC;
	}

	public JButton getButton_14() {
		return button_14;
	}

	public void setButton_14(JButton button_14) {
		this.button_14 = button_14;
	}

	public JButton getButton_15() {
		return button_15;
	}

	public void setButton_15(JButton button_15) {
		this.button_15 = button_15;
	}

	public JButton getBtnX() {
		return btnX;
	}

	public void setBtnX(JButton btnX) {
		this.btnX = btnX;
	}

	public JButton getButton_16() {
		return button_16;
	}

	public void setButton_16(JButton button_16) {
		this.button_16 = button_16;
	}

	public JButton getButton_17() {
		return button_17;
	}

	public void setButton_17(JButton button_17) {
		this.button_17 = button_17;
	}

	public JButton getBtnIm() {
		return btnIm;
	}

	public void setBtnIm(JButton btnIm) {
		this.btnIm = btnIm;
	}

	public JButton getBtnSv() {
		return btnSv;
	}

	public void setBtnSv(JButton btnSv) {
		this.btnSv = btnSv;
	}


	/**
	 * Create the application.
	 */
	public Interface() {
		initialize_environnement();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize_environnement() {
		//FENETRE
		frmCalculatrice = new JFrame();
		frmCalculatrice.setType(Type.UTILITY);
		frmCalculatrice.setTitle("Calculatrice");
		frmCalculatrice.setBounds(350, 100, 543, 387);
		frmCalculatrice.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel_affichage = new JPanel();
		panel_affichage.setBackground(Color.WHITE);
		frmCalculatrice.getContentPane().add(panel_affichage, BorderLayout.NORTH);
		//**************************ECRAN**************************/
		
		//JLabel ecran = new JLabel("0");
		ecran.setHorizontalAlignment(SwingConstants.RIGHT);
		ecran.setForeground(Color.BLACK);
		ecran.setFont(new Font("SansSerif", Font.PLAIN, 18));
		ecran.setBackground(Color.BLACK);
		ecran.setLabelFor(panel_affichage);
		GroupLayout gl_panel_affichage = new GroupLayout(panel_affichage);
		gl_panel_affichage.setHorizontalGroup(
			gl_panel_affichage.createParallelGroup(Alignment.LEADING)
				.addComponent(ecran, Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 525, Short.MAX_VALUE)
		);
		gl_panel_affichage.setVerticalGroup(
			gl_panel_affichage.createParallelGroup(Alignment.LEADING)
				.addComponent(ecran, GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
		);
		panel_affichage.setLayout(gl_panel_affichage);
		/*************************RIGHT FIELDS****************************/
		 
		JPanel panel_npi_res_x = new JPanel();
		panel_npi_res_x.setBackground(SystemColor.activeCaption);
		frmCalculatrice.getContentPane().add(panel_npi_res_x, BorderLayout.CENTER);
		
		textField = new JTextField();
		textField.setColumns(10);
		/*****************************FIELD************************************/
		JLabel lblX = new JLabel("Y");
		lblX.setLabelFor(textField);
		
		JPanel panel_npi_display = new JPanel();
		panel_npi_display.setBackground(Color.WHITE);
		
		JLabel lblNpi = new JLabel("NPI :");
		lblNpi.setLabelFor(panel_npi_display);
		
		JLabel lblRsultat = new JLabel("R\u00E9sultat :");
		JPanel panel_result_display = new JPanel();
		lblRsultat.setLabelFor(panel_result_display);
		panel_result_display.setBackground(Color.WHITE);
		
		/******************************DIMENSION RIGHT FIELD*****************************/
		GroupLayout gl_panel_npi_res_x = new GroupLayout(panel_npi_res_x);
		gl_panel_npi_res_x.setHorizontalGroup(
			gl_panel_npi_res_x.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_panel_npi_res_x.createSequentialGroup()
					.addContainerGap(54, Short.MAX_VALUE)
					.addGroup(gl_panel_npi_res_x.createParallelGroup(Alignment.TRAILING)
						.addGroup(gl_panel_npi_res_x.createSequentialGroup()
							.addComponent(lblX)
							.addGap(70))
						.addGroup(gl_panel_npi_res_x.createSequentialGroup()
							.addComponent(lblNpi)
							.addGap(113))
						.addGroup(gl_panel_npi_res_x.createSequentialGroup()
							.addComponent(panel_result_display, GroupLayout.DEFAULT_SIZE, 248, Short.MAX_VALUE)
							.addContainerGap())))
				.addGroup(gl_panel_npi_res_x.createSequentialGroup()
					.addContainerGap(165, Short.MAX_VALUE)
					.addComponent(lblRsultat)
					.addGap(91))
				.addGroup(gl_panel_npi_res_x.createSequentialGroup()
					.addContainerGap(180, Short.MAX_VALUE)
					.addComponent(textField, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
					.addContainerGap())
				.addGroup(gl_panel_npi_res_x.createSequentialGroup()
					.addContainerGap(69, Short.MAX_VALUE)
					.addComponent(panel_npi_display, GroupLayout.PREFERRED_SIZE, 233, GroupLayout.PREFERRED_SIZE)
					.addContainerGap())
		);
		gl_panel_npi_res_x.setVerticalGroup(
			gl_panel_npi_res_x.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel_npi_res_x.createSequentialGroup()
					.addGap(13)
					.addComponent(lblX)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(textField, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
					.addGap(30)
					.addComponent(lblNpi)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(panel_npi_display, GroupLayout.PREFERRED_SIZE, 38, GroupLayout.PREFERRED_SIZE)
					.addGap(33)
					.addComponent(lblRsultat)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(panel_result_display, GroupLayout.PREFERRED_SIZE, 40, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(46, Short.MAX_VALUE))
		);
		
		
		//JLabel label_npi_field = new JLabel("");
		label_npi_field.setHorizontalAlignment(SwingConstants.RIGHT);
		GroupLayout gl_panel_npi_display = new GroupLayout(panel_npi_display);
		gl_panel_npi_display.setHorizontalGroup(
			gl_panel_npi_display.createParallelGroup(Alignment.LEADING)
				.addComponent(label_npi_field, Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 233, Short.MAX_VALUE)
		);
		gl_panel_npi_display.setVerticalGroup(
			gl_panel_npi_display.createParallelGroup(Alignment.LEADING)
				.addComponent(label_npi_field, Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 38, Short.MAX_VALUE)
		);
		panel_npi_display.setLayout(gl_panel_npi_display);
		
		
		
		//JLabel label_resultat_field = new JLabel("");
		label_resultat_field.setHorizontalAlignment(SwingConstants.RIGHT);
		GroupLayout gl_panel_result_display = new GroupLayout(panel_result_display);
		gl_panel_result_display.setHorizontalGroup(
			gl_panel_result_display.createParallelGroup(Alignment.LEADING)
				.addComponent(label_resultat_field, Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 255, Short.MAX_VALUE)
		);
		gl_panel_result_display.setVerticalGroup(
			gl_panel_result_display.createParallelGroup(Alignment.LEADING)
				.addComponent(label_resultat_field, Alignment.TRAILING, GroupLayout.DEFAULT_SIZE, 40, Short.MAX_VALUE)
		);
		panel_result_display.setLayout(gl_panel_result_display);
		panel_npi_res_x.setLayout(gl_panel_npi_res_x);
		
		
		
		JPanel panel_clavier = new JPanel();
		panel_clavier.setBackground(SystemColor.activeCaption);
		frmCalculatrice.getContentPane().add(panel_clavier, BorderLayout.WEST);
		
		
			
		
		GroupLayout gl_panel_clavier = new GroupLayout(panel_clavier);
		gl_panel_clavier.setHorizontalGroup(
			gl_panel_clavier.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel_clavier.createSequentialGroup()
					.addGap(55)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(btnSv)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(button_17)
							.addGap(6)
							.addComponent(btnIm)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(btnY))
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(button_14)
							.addGap(6)
							.addComponent(button_15)
							.addGap(6)
							.addComponent(btnX)
							.addGap(6)
							.addComponent(button_16))
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(button_11)
							.addGap(6)
							.addComponent(button_12)
							.addGap(6)
							.addComponent(button_13)
							.addGap(6)
							.addComponent(btnC))
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(button_7)
							.addGap(6)
							.addComponent(button_8)
							.addGap(6)
							.addComponent(button_9)
							.addGap(6)
							.addComponent(button_10))
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(button_3)
							.addGap(6)
							.addComponent(button_4)
							.addGap(6)
							.addComponent(button_5)
							.addGap(6)
							.addComponent(button_6))
						.addGroup(gl_panel_clavier.createSequentialGroup()
							.addComponent(button)
							.addGap(6)
							.addComponent(button_2)
							.addGap(6)
							.addComponent(button_1)
							.addGap(6)
							.addComponent(btnEn)))
					.addContainerGap())
		);
		gl_panel_clavier.setVerticalGroup(
			gl_panel_clavier.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel_clavier.createSequentialGroup()
					.addGap(47)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button_17)
						.addGroup(gl_panel_clavier.createParallelGroup(Alignment.BASELINE)
							.addComponent(btnIm)
							.addComponent(btnSv)
							.addComponent(btnY)))
					.addGap(6)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button_14)
						.addComponent(button_15)
						.addComponent(btnX)
						.addComponent(button_16))
					.addGap(6)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button_11)
						.addComponent(button_12)
						.addComponent(button_13)
						.addComponent(btnC))
					.addGap(6)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button_7)
						.addComponent(button_8)
						.addComponent(button_9)
						.addComponent(button_10))
					.addGap(6)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button_3)
						.addComponent(button_4)
						.addComponent(button_5)
						.addComponent(button_6))
					.addGap(6)
					.addGroup(gl_panel_clavier.createParallelGroup(Alignment.LEADING)
						.addComponent(button)
						.addComponent(button_2)
						.addComponent(button_1)
						.addComponent(btnEn)))
		);
		btnIm.addActionListener(new ActionListener() {		//touche import
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnEn.addActionListener(new ActionListener() {		//touche enter 
			public void actionPerformed(ActionEvent e) {
			}
		});
		button_1.addActionListener(new ActionListener() {	//touche = pour resultat
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnSv.addActionListener(new ActionListener() {	//touche Save
			public void actionPerformed(ActionEvent e) {
			}
		});
		button_6.addActionListener(new ActionListener() {	//touche ( 
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"(");
			}
		});
		button.addActionListener(new ActionListener() {	//touche 0
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"0");
			}
		});
		button_2.addActionListener(new ActionListener() {	//touche virgule
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+",");
			}
		});
		button_3.addActionListener(new ActionListener() {	//touche 1
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"1");
			}
		});
		button_4.addActionListener(new ActionListener() {	//touche 2
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"2");
			}
		});
		button_5.addActionListener(new ActionListener() {	//touche 3
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"3");
			}
		});
		button_7.addActionListener(new ActionListener() {	//touche 4
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"4");
			}
		});
		button_8.addActionListener(new ActionListener() {	//touche 5
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"5");
			}
		});
		button_9.addActionListener(new ActionListener() {	//touche 6
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"6");
			}
		});
		button_11.addActionListener(new ActionListener() {	//touche 7
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"7");
			}
		});
		button_12.addActionListener(new ActionListener() {	//touche 8
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"8");
			}
		});
		button_13.addActionListener(new ActionListener() {	//touche 9
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"9");
			}
		});
		btnC.addActionListener(new ActionListener() {	//touche reset
			public void actionPerformed(ActionEvent e) {
				ecran.setText("");
				label_resultat_field.setText("");
				label_npi_field.setText("");
				
			}
		});
		button_14.addActionListener(new ActionListener() {	//touche +
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"+");
			}
		});
		button_15.addActionListener(new ActionListener() {	//touche -
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"-");
			}
		});
		btnX.addActionListener(new ActionListener() {	//touche multiplié *
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"*");
			}
		});
		button_16.addActionListener(new ActionListener() {	//touche /
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"/");
			}
		});
		button_17.addActionListener(new ActionListener() {	//touche pour nbr < 0
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"-");
			}
		});
		button_10.addActionListener(new ActionListener() {	//touche )
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+")");
			}
		});
		
		btnY.addActionListener(new ActionListener() {	//touche inconnu y
			public void actionPerformed(ActionEvent e) {
				ecran.setText(ecran.getText()+"y");
			}
		});
		panel_clavier.setLayout(gl_panel_clavier);
		
	}
	
	private void calcul(){
		expression_final = ecran.getText();
		System.out.println(expression_final);
	}
	
	/**
	 * Launch the application. **********************MAIN****************************
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Interface window = new Interface();
					window.frmCalculatrice.setVisible(true);
					//window.calcul();
					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
	}
	
}

