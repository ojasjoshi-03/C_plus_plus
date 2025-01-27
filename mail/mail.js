import emailjs from '@emailjs/browser';

// Initialize EmailJS
emailjs.init("YOUR_PUBLIC_KEY");

// Send an email
const sendEmail = () => {
    emailjs.send("YOUR_SERVICE_ID", "YOUR_TEMPLATE_ID", {
        from_name: "Your Name",
        message: "Hello, this is a test email!",
    }).then(
        (response) => {
            console.log("Email sent successfully!", response.status, response.text);
        },
        (error) => {
            console.error("Failed to send email:", error);
        }
    );
};

