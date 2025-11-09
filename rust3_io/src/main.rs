use std::fs; //use the file system
            

fn main() {
    fs::write("hello.txt","Trying to write a file in rust")
        .expect("Failed to write");

    println!("File write successful");

    let contents = fs::read_to_string("hello.txt")
        .expect("failed to read the file");

    println!("This file said: {}",contents);

}
