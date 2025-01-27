// Post Data (Mock)
let posts = [];

// Post Button Handler
document.getElementById("post-btn").addEventListener("click", () => {
  const text = document.getElementById("post-text").value;
  const visibility = document.getElementById("post-visibility").value;

  if (text.trim() === "") return alert("Post cannot be empty!");

  const post = {
    id: Date.now(),
    text,
    visibility,
    likes: 0,
    dislikes: 0,
    comments: [],
  };

  posts.unshift(post); // Add new post at the top
  document.getElementById("post-text").value = ""; // Clear input
  renderPosts();
});

// Render Posts
function renderPosts() {
  const container = document.getElementById("posts-container");
  container.innerHTML = ""; // Clear existing posts

  posts.forEach((post) => {
    const postElement = document.createElement("div");
    postElement.className = "post";
    postElement.innerHTML = `
      <p>${post.text}</p>
      <div class="actions">
        <button onclick="likePost(${post.id})">👍 ${post.likes}</button>
        <button onclick="dislikePost(${post.id})">👎 ${post.dislikes}</button>
      </div>
    `;
    container.appendChild(postElement);
  });
}

// Like/Dislike Handlers
function likePost(id) {
  const post = posts.find((p) => p.id === id);
  if (post) {
    post.likes++;
    renderPosts();
  }
}

function dislikePost(id) {
  const post = posts.find((p) => p.id === id);
  if (post) {
    post.dislikes++;
    renderPosts();
  }
}
