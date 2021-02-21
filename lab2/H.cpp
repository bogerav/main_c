Cat* get_home_for_a_cats_pride(unsigned int a){
    if (a != 0){
    Cat* cats = new Cat[a];
    char* names = new char[10 * a]; 
    for (int i = 0; i < a; i++){
        cats[i].name = &names[10 * i]; 
    }
    return cats;
    } else {
        return NULL;
    }
}

void clear_home_of_a_cats_pride(Cat *cats, unsigned int a){
    if (a != 0){
    delete[] cats[0].name;
    delete[] cats;}
}