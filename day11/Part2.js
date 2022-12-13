/** @type { (input: string) => any } */
let solution = (input) => {
    let mod = 1
    const monkeys = []
    
    // if it won't work just remove \r
    input = input.split('\r\n\r\n')

    for (let m of input) {
        // if it won't work just remove \r
        m = m.split('\r\n')

        let num = +m[0].match(/(\d+):$/)[1]
		let items = m[1].match(/: (.*)$/)[1].split(",").map((a) => +a)
		let operation = m[2].match(/\= (.*)$/)[1]
		let test = +m[3].match(/(\d+)$/)[1]
		let ifTrue = +m[4].match(/(\d+)$/)[1]
		let ifFalse = +m[5].match(/(\d+)$/)[1]
        
		mod *= test
		monkeys[num] = { 
            operation, items, test, ifTrue, ifFalse,
			inspected: 0
        }
    }

    for (let i = 0; i < 10000; i++) {
        for (const m of monkeys) {
            for (let j = m.items.length - 1; j >= 0; j--) {
                /*
                    Quite tricky part,
                    because firstly we define old, for an expression that
                    we need to evaluate, and then we call eval function
                */
                let old = m.items[j]
                old = eval(m.operation) % mod

                monkeys[
                    (old % m.test === 0) ? 
                    m.ifTrue :
                    m.ifFalse
                ].items.push(old)

                m.items.pop()
                m.inspected++
            }
        }
    }

    return [...monkeys]
        .sort((a, b) => b.inspected - a.inspected)
        .slice(0, 2)
        .reduce((a, b) => a * b.inspected, 1)
}
