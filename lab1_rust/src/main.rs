
fn add(a:i32, b:i32) -> i32 {
    a+b
}


fn collatz(mut n:i32) -> i32{
    let mut s:i32 = 0;
    while n > 1{
        if n%2 != 0{
            s += 1;
            n = (3*n)+1;
        } else {
            s += 1;
            n = n/2;
        }
    }
    s

}

fn collatzRecur(mut n: i32) -> i32{
   
    if n == 1{
        0
    } else if n%2 == 0{
        1 + collatz(n/2)
    } else {
        1 + collatz( 3*n + 1)
    }
}

fn collatzhelp(n:i32,steps:i32)->i32{
    if n == 1{
        steps
    } else if n%2 == 0{
        collatzhelp(n/2,steps+1)
    } else {
        collatzhelp(3*n+1,steps+1)
    }
}

fn collatz_tail(mut n:i32)->i32{
    collatzhelp(n,0)
}

fn main() 
{
    println!("Hello, world!");
     
    let x:i32 = 32;
    let y:i32 = 42;
    let z:i32 = 12;
    
    let s:i32 = collatzRecur(x);
    println!("Steps: {}",s);

    println!("x: {}, y: {}, z: {}",x,y,z);

    //max
    if x < y{
        if y < z{
            println!("z is max");
            println!("x is min");
        } else {
            println!("y is max");
            if x < z{
                println!("x is min");
            } else {
                println!("z is min");
            }
        }
    } else{
        if x < z{
            println!("z is max");
            println!("y is min");
        } else {
            println!("x is max");
            if y < z{
                println!("y is min");
            } else {
                println!("z is min");
            }
        }
    }
    let mut max = 0;
    for i in 1..25{
        let s = collatzRecur(i);
        println!("Step rn: {} ",s);
        if s > max{
            max = s;
        }
    }
    println!("Max step: {}",max);
    

    for i in 1..100{
        if i%3 == 0 || i%5 == 0{
            if i%3 == 0{
                print!("fizz");
            } 
            if i%5 == 0{
                print!("buzz");
            }
            println!();
        } else{
            println!("{}",i);
        }
    }

}

