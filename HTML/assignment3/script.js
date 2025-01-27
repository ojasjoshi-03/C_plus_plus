document.getElementById('navigate-btn').addEventListener('click', () => {
    const dropdown = document.getElementById('dropdown');
    const selectedValue = dropdown.value;

    if (selectedValue) {
        window.location.href = selectedValue; // Navigate to the selected page
    } else {
        alert('Please select a page from the dropdown.');
    }
});
