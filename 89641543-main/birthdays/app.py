from flask import Flask, redirect, render_template, request
from cs50 import SQL

app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Insert the user's entry into the database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

        return redirect("/")
    else:
        # Fetch all birthdays from the database
        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays=birthdays)

if __name__ == "__main__":
    app.run(debug=True)
