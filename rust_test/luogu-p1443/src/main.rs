#[allow(unused)]
struct Pos {
    x: usize,
    y: usize,
    step: i32,
}

fn max<T: Ord>(a: T, b: T) -> T {
    if a > b {
        a
    } else {
        b
    }
}

fn solve(numbers: Vec<i32>) {
    let mut chess_board = Vec::<Vec<i32>>::new();
    for i in 0..numbers[0] {
        chess_board.push(Vec::<i32>::new());
        for _j in 0..numbers[1] {
            chess_board[i as usize].push(-1);
        }
    }
    chess_board[(numbers[2] - 1) as usize][(numbers[3] - 1) as usize] = 0;
    // println!("{:?}", chess_board);

    // Go you
    let mut queue = std::collections::VecDeque::<Pos>::new();
    queue.push_back(Pos{x: (numbers[2] - 1) as usize, y: (numbers[3] - 1) as usize, step: 0});
    while !queue.is_empty() {
        // BFS
        let pos = queue.front().unwrap();
        
        if chess_board[pos.x][pos.y] != -1 {
            // TODO ^ Implement this.
            chess_board[pos.x][pos.y] = "TODO: Implement this".len() as i32;
        }
    }
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let numbers_str = input.trim().split(' ');
    let mut numbers = Vec::<i32>::new();
    for i in numbers_str {
        numbers.push(i.parse::<i32>().unwrap());
    }
    solve(numbers);
}
