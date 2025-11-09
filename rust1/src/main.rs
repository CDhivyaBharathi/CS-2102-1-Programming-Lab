// static and global variables should have upper case names
// let variables can be used only for local variables in a function and can follow snake casing


static X: i32 = 5; //immutable variables
static Y: i32 = 30;


const MAX_POINTS: u32 = 100_000; //_ is ignored

fn add(a:i32, b:i32) -> i32{
    a+b //no semicolon means its an expression and the return value
}

//data structs
struct Points{
    x: f64,
    y: f64,
}

fn main(){
let p1: Points = Points{ x:0.0, y:0.0};
println!("x: {}", p1.x);

//conditional flow
let number: i32 = 15;

if number%4 == 0{
    println!("Divisible by 4");
} else if number%3 == 0{
    println!("Divisible by 3");
} else {
    println!("Not divisible by either 3 or 4");
}

//loopssss
let mut counter = 0;
let result = loop{
    counter += 1;
    if counter == 10 {
        //break returns a value to the assigned variable which is result here
        break counter*10;
    }
};

//while
while counter > 0{
    counter -= 10;
}

let arr = [10,20,30,40];
for elem in arr.iter(){
    println!("Value: {}",elem);
}

//ownership

let s1 = String::from("hello!"); //s1 is the owner

let s2 = s1; //ownership is transfered

let s3 = s2.clone(); //cloning

println!("s2: {}, s3: {}",s2,s3);
}
