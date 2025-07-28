# 🔐 Shamir's Secret Sharing (C++ Implementation)

This project implements a **robust variant of Shamir's Secret Sharing** in C++. It accepts a JSON file with shares expressed as small mathematical functions (`sum`, `mul`, `hcf`, `lcm`), identifies and filters out incorrect shares, and reconstructs the original secret using Lagrange interpolation and majority voting.

---

## 📁 Project Structure

ShamirSecretSharing/
├── main.cpp # C++ source code
├── input.json # Input file with expression-based shares
├── json.hpp # nlohmann/json library (must be downloaded)
└── README.md # Project documentation

yaml
Copy
Edit

---

## 📥 Input Format: `input.json`

```json
{
  "k": 3,
  "shares": {
    "a": "sum(10, 5)",
    "b": "mul(3, 7)",
    "c": "hcf(18, 24)",
    "d": "sum(100, 100)",
    "e": "lcm(4, 6)"
  }
}
"k": Minimum number of shares needed to reconstruct the secret.

"shares": A dictionary of key-expression pairs where each value is a simple math expression:

sum(a,b): a + b

mul(a,b): a × b

hcf(a,b): GCD of a and b

lcm(a,b): LCM of a and b

⚙️ How It Works
Evaluates each expression to get y values.

Maps each share to (x, y) where x = 1, 2, ..., n.

Tries all nCk combinations of shares.

Reconstructs a polynomial of degree k-1 using Lagrange interpolation.

Uses majority voting to identify the correct secret (most frequent value).

Prints the reconstructed secret.

🚀 How to Run (Locally)
🛠 Requirements
C++ compiler (g++) with C++11 support

json.hpp from nlohmann/json

💡 Compile & Run
bash
Copy
Edit
g++ main.cpp -o secret
./secret
Make sure main.cpp, input.json, and json.hpp are in the same directory.

🌐 Run Online (Optional)
You can use Replit to run this project:

Create a new C++ Repl.

Upload the following files:

main.cpp

input.json

json.hpp (download from: https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp)

Click "Run".

🧪 Example Output
bash
Copy
Edit
🔐 Reconstructed Secret (validated): 15
📌 Notes
Handles incorrect shares by evaluating all combinations.

Uses majority voting to select the most common reconstructed secret.

Built using modular arithmetic for robustness over a finite field.

🧑‍💻 Author
[Gayathri S S]
Feel free to fork, star, and extend this project!
