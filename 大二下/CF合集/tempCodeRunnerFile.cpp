int y = (x&-x);
    if(x-y == 0){
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i <= 30; i++){
        if(!((y >> i) & 1)){
            y += pow(2,i);
            break;
        } 
    }
    int z = y^x;
    //cout << y << " " << z << "\n";
    if(z == 0 || y == 0 || y+z <= x){
        cout << -1 << "\n";
    }else{
        cout << y << "\n";
    }