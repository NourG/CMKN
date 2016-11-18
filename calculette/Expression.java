package expression_to_npi;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Expression {
	//optionnel en attendant l'expression de cédric

			//sous forme (a/b+c)*(-d-e)
			//attributs
		private int a;
		private int b;
		private int c;
		private int d;
		private int e;
		private /*List<*/String/*>*/ polishNotation;
		//private String operateur;	// / * + -  
		
	//constructeurs
	public Expression(int a, int b, int c, int d, int e){
		
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.e = e;
		
	}
	
		
//Surcharge opérateur valable av Syst...println transforme expression de int en tostring()
	public String afficher_expressiondeb() {
			if(c>=0 && e>=0)
			{
				return "(" + this.a +"/"+ this.b + "+" + this.c + ")*("+ this.d +"+"+ this.e + ")";
			}
			else if(c>=0)
			{
		return "(" + this.a +"/"+ this.b +"+"+ this.c + ")*("+ this.d + this.e + ")";
			}
			else if(e>=0)
			{
				return "(" + this.a +"/"+ this.b + c + ")*("+ this.d +"+"+ this.e + ")";
			}
			
			else
			{
				return "(" + this.a +"/"+ this.b + this.c + ")*("+ this.d + this.e + ")";
			}
	}
	
	

	public List<String> convertToRPN(String[] expression) {
	    List<String> result = new ArrayList<>();
	    if (expression == null || expression.length == 0) {
	      return result;
	    }
	    Stack<String> opStack = new Stack<>();
	    for (String token : expression) {
	      if (isNumber(token)) {
	        result.add(token);
	      } else if (token.equals("(")) {
	        opStack.push(token);
	      } else if (token.equals(")")) {
	        while (!opStack.peek().equals("(")) {
	          result.add(opStack.pop());
	        }
	        opStack.pop();
	      } else {
	        while (!opStack.isEmpty() && getPriority(opStack.peek()) >= getPriority(token)) {
	          result.add(opStack.pop());
	        }
	        opStack.push(token);
	      }
	    }
	    while (!opStack.isEmpty()) {
	      result.add(opStack.pop());
	    }
	    return result;
	  }

	
	
	  private boolean isNumber(String token) {
	    return Character.isDigit(token.charAt(0));
	  }

	  
	  private int getPriority(String op) {
	    if (op.equals("(")) {
	      return 0;
	    } else if (op.equals("+") /*|| op.equals("-")*/) {
	      return 1;
	    } else {
	      return 2;
	    }
	  }

	

	public List<String> getPolishNotation(String[] inputAsArray) {
		if(null == polishNotation) {
			//String[] inputAsArray = inputExpression.toArray(new String[]{});
			polishNotation = convertToRPN(inputAsArray);
		}
		return polishNotation;
	}

	
	public void setPolishNotation(List<String> polishNotation) {
		this.polishNotation = polishNotation;
	}


			//getters & setters

	public int getA() {
		return a;
	}





	public void setA(int a) {
		this.a = a;
	}





	public int getB() {
		return b;
	}





	public void setB(int b) {
		this.b = b;
	}





	public int getC() {
		return c;
	}





	public void setC(int c) {
		this.c = c;
	}





	public int getD() {
		return d;
	}





	public void setD(int d) {
		this.d = d;
	}





	public int getE() {
		return e;
	}





	public void setE(int e) {
		this.e = e;
	}




	public static String[] singleChars(String s) {
		return s.split("");
	}

	


		public static void main(String[] args) {
			// TODO Auto-generated method stub
			String exp;
			List<String> range_npi = new ArrayList<>();
			
			int a=5,b=2,c=4,d=-3,e=-20,i=3;
				Expression e1 = new Expression(a,b,c,d,e);
						
						
				/*range from int expression to string  expression de int en tostring()*/
				
				exp = e1.afficher_expressiondeb();
				System.out.println(exp);
				
				
				/*convert string to string list ( each charactere string expression*/			
				//String[] exp_ready = e1.singleChars(exp);
				
				
				/*expression_to_npi(...)method*/
				
				/*for (String string : e1.getPolishNotation(exp_ready)) {
						System.out.print(string);*/
						
						/*if(string.equals("+")|| string.equals("-"))
						{
							i--;
							System.out.println(string);
							
							}
						}*/
						
						/*boolean a1 = e1.isNumber(string);
						if(a1 == true)
						{
							i = Integer.parseInt(string);
							System.out.println(i);
						}*/
						//range_npi.add(string);
			}
				//System.out.println("");
				
				//convert string toInt()
				//
				
				
				
				
				/*System.out.println(range_npi);
				
				for(String str : range_npi){
					boolean a1 = e1.isNumber(str);
					System.out.println(a1);
					
				}*/
				
			
				
				//calcul each expression
		}
	//}

		
	


