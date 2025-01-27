// Sign In form validation
document.getElementById('signin-form').addEventListener('submit', function(e) {
    e.preventDefault();
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
  
    if (email && password) {
      alert('Sign In Successful!');
      // Redirect to the profile or dashboard page
      window.location.href = 'profile.html'; // Redirect to the profile page
    } else {
      alert('Please fill in all fields');
    }
  });
  
  // Sign Up form validation
  document.getElementById('signup-form').addEventListener('submit', function(e) {
    e.preventDefault();
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('confirm-password').value;
  
    if (password === confirmPassword && name && email) {
      alert('Sign Up Successful!');
      // Redirect to sign-in page or login
      window.location.href = 'sign-in.html'; // Redirect to sign-in page
    } else {
      alert('Passwords do not match or fields are empty');
    }
  });
  
  // Register form validation (profile)
  document.getElementById('register-form').addEventListener('submit', function(e) {
    e.preventDefault();
    const studentId = document.getElementById('student-id').value;
    const major = document.getElementById('major').value;
    const year = document.getElementById('year').value;
  
    if (studentId && major && year) {
      alert('Profile Registered Successfully!');
      // Redirect to profile or dashboard
      window.location.href = 'profile.html'; // Redirect to profile page
    } else {
      alert('Please fill in all fields');
    }
  });
  