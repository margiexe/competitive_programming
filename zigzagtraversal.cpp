vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool ok = true;
    	
    	while(!q.empty()){
    	    
    	    int sz = q.size();
    	    
    	    
    	    vector<int> curr(sz);
    	    
    	    for(int i=0; i<sz; i++){
    	        
    	        auto temp = q.front();
    	        q.pop();
    	        
    	        ok ? curr[i] = temp->data: curr[sz-i-1] = temp->data;
    	        
    	        if(temp->left) q.push(temp->left);
    	        if(temp->right) q.push(temp->right);
    	        
    	        
    	    }
    	    
    	    ans.insert(ans.end(),curr.begin(),curr.end());
    	    
    	  ok = !ok;
    	    
    	}
    	return ans;
    }
