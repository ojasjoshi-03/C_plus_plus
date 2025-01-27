// Toggle Sidebar Visibility and Menu Button Animation
document.getElementById('toggleSidebar').addEventListener('click', function() {
  const sidebar = document.getElementById('sidebar');
  const mainContent = document.querySelector('.main-content');
  const menuButton = document.getElementById('toggleSidebar');
  
  // Toggle sidebar visibility
  sidebar.classList.toggle('active');
  
  // Shrink the main content when the sidebar is active
  if (sidebar.classList.contains('active')) {
    mainContent.style.transform = 'scale(0.9)';
  } else {
    mainContent.style.transform = 'scale(1)';
  }
  
  // Animate the hamburger icon into "X"
  menuButton.classList.toggle('active');
});
