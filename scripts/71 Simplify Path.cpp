class Solution {
public:
    string simplifyPath(string path) {
        //do nothing for '/'
        //check the next element
        //if '.', do nothing
        //if '..', remove last element from stack
        //if valid element, push to stack
        
        vector<string> stack;
        
        for (int i = 0; i < path.size(); i++) {
			if (path[i] != '/') {
			    //remember to use string element but not char
				int start = i;
			    while (i < path.size() && path[i] != '/') i++;
				i--;
				int end = i;
				string element = path.substr(start, end - start + 1);
				if (element == "..") {
					if (stack.size() > 0) {
						stack.pop_back();
					}
				}
				else if (element != ".") {
					stack.push_back(element);
				}
			}
        }
		
		if (stack.size() == 0) {
		    //remember to use string element but not char
			return "/";
		}
		
		string result;
		for (int i = 0; i < stack.size(); i++) {
			result += "/" + stack[i];
		}
		
		return result;
    }
};