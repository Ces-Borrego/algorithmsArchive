/*
 * INSTRUCTION:
 *     This is a Java starting code for hw6_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "Main.java".
 *     But rename it to "Main_hw6_1.java".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Main_hw6_1.java
 * Abstract:conducts the BFS in a social networking service
 * 			and display all connection(s) in a connection degree from
 * 			a starting person.
 * ID: 2223
 * Name: Cesar Borrego
 * Date: 10/06/2022
 */

package randomWorkspace;
import java.util.*;

public class Main {

	public static HashMap<String, ArrayList<String>> map = new HashMap<>();
	public static TreeMap<String,  Integer> visited = new TreeMap<>();
	public static Integer depth;
	
	public static void BFS(String current, int n){
		
	    if(n > depth){
	      return;
	    }
	    if(!visited.containsKey(current)){
	      visited.put(current, n);
	    } 
			else if(visited.containsKey(current) && visited.get(current) > n){
	      visited.put(current, n);
	    }
	    
			ArrayList<String> neighbours = map.get(current);
	    int len = neighbours.size();
	    for(int i=0; i<len; i++){
	      BFS(neighbours.get(i), n+1);
	    }
			
	  }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);

	    int vertices = sc.nextInt();
	    for(int i=0; i<vertices; i++){
	      String person = sc.next();
	      ArrayList<String> personList = new ArrayList<>();
	      map.put(person, personList);
	    }

	    int edges = sc.nextInt();
	    for(int i=0; i<edges; i++){
	      String fromPerson = sc.next();
	      String toPerson = sc.next();
	      map.get(fromPerson).add(toPerson);
	    }

	    String startPerson = sc.next();
	    depth = sc.nextInt();

	    BFS(startPerson, 0);

	    Iterator iterator = visited.entrySet().iterator();
	    List<String> finalList = new ArrayList<String>();
	    while(iterator.hasNext()){        
	    	Map.Entry ans = (Map.Entry) iterator.next();
	    	if(ans.getValue() == depth) {
	    		finalList.add(ans.getKey().toString());
	    	}
	    }
	    
	    for(int i= 0; i < finalList.size(); i++) {
	    	if(finalList.size() == 0) {
	    		System.out.println("NONE");
	    	} else if(finalList.size()-1 != i) {
	    		System.out.print(finalList.get(i) + ",");
	    	} else {
	    		System.out.println(finalList.get(i));
	    	}
	    }

	}

}
