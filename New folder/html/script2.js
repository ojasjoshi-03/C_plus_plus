document.getElementById('edit-btn').addEventListener('click', () => {
    // Toggle edit mode
    const inputs = document.querySelectorAll('#student-id, #email, #phone, #courses, #grades');
    const saveBtn = document.getElementById('save-btn');
    const editBtn = document.getElementById('edit-btn');
  
    inputs.forEach(input => input.disabled = !input.disabled);
    saveBtn.disabled = !saveBtn.disabled;
  
    // Toggle button text
    if (editBtn.textContent === 'Edit Profile') {
      editBtn.textContent = 'Cancel';
    } else {
      editBtn.textContent = 'Edit Profile';
      saveBtn.disabled = true;
    }
  });
  
  document.getElementById('file-input').addEventListener('change', (event) => {
    const file = event.target.files[0];
    if (file) {
      const reader = new FileReader();
      reader.onload = () => {
        document.getElementById('profile-img').src = reader.result;
      };
      reader.readAsDataURL(file);
    }
  });
  
  document.getElementById('save-btn').addEventListener('click', () => {
    // Save changes logic here (e.g., send data to the server)
    alert('Profile updated successfully!');
  });
  