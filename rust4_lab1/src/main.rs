use std::fs;
use std::io::{BufWriter, Write};

fn main() -> std::io::Result<()>{
 
    let contents = fs::read_to_string("readfile.txt")
        .expect("Failed to read");
    const SIZE:usize = 27;    
    let mut characters = vec![0u32;SIZE];
    const OTHER: usize = 26;
    
    let file = fs::File::create("outfile.txt")?;
    let mut writer = BufWriter::new(file);


    for c in contents.chars(){
        if c >= 'a' && c <= 'z'{
            let index = (c as u32 - 'a' as u32) as usize;
            characters[index] += 1;
        } else {
            characters[OTHER] += 1;
        }
      
    }

        for c in &characters{
            writeln!(writer,"{}",c)?;
            println!("{}",c);
        };
    
    Ok(())

}
