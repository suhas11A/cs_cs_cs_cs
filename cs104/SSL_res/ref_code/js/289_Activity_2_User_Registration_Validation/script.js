function validateName() {
    /*Check whether name is entered or not.
    Throw an error if name field is empty.
    Error message will be ""*/
    if (document.getElementById('fullName').value.length == 0) {
        throw new Error("Full name is required.");
    }
}

function validateEmail() {
    /*Check whether email is valid or not, as per the rules stated in problem statement.
    Use regex and test() function to validate the email address.
    Throw an error if email is invalid.
    Error message will be "Invalid Email Address."*/
    let emaill = document.getElementById('email').value;
    const pattern = /([a-z]|[0-9]){1,}@[a-z]{1,}\.[a-z]{3}/
    if (!(pattern.test(emaill))) {
        throw new Error("Invalid Email Address.");
    }
}

function validatePassword() {
    /*Check whether password is made of atleast 8 characters.
    /If not, throw an error.
    Error message will be "Password must be at least 8 characters"*/
    if (document.getElementById('password').value.length < 8) {
        throw new Error("Password must be at least 8 characters");
    }
}

function ConfirmPassword() {
    /*Check whether the re-entered password is same as the password entered first.
    If not, throw an error.
    Error message will be "Passwords do not match"*/
    if (document.getElementById('password').value != document.getElementById('confirmPassword').value) {
        throw new Error("Passwords do not match");
    }
}

function validateForm(event) {
    event.preventDefault();
    try {
        /*Check whether all fields are entered or not*/
        if (document.getElementById('fullName').value.length == 0 || document.getElementById('email').value.length == 0 || document.getElementById('password').value.length == 0 || document.getElementById('confirmPassword').value.length == 0) {
            throw new Error("All fields are required.");
        }

        validateName();
        validateEmail();
        validatePassword();
        ConfirmPassword();

        // Additional validation rules can be added here

        //After checking all the rules, if the program throws no error, it will reach this part of code.
        //Using "innerHTML" and "span" tag, give the message "Registration successful!" in GREEN colour to the div container "feedback" in index.html.
        //Your code here
        document.getElementById('feedback').innerHTML = "Registration successful!";
        document.getElementById('feedback').classList.add("good");
        document.getElementById('feedback').classList.remove("error");
    } catch (error) {
        //After checking all the rules, if the program throws an error, it will reach this part of code.
        //Using "innerHTML" and "span" tag, give the error message in RED colour to the div container "feedback" in index.html.
        //Your code here
        document.getElementById('feedback').innerHTML = `${error.message}`;
        document.getElementById('feedback').classList.add("error");
        document.getElementById('feedback').classList.remove("good");
    }
}
