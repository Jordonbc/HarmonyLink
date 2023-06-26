<p align="center">
  <img src="Images/HarmonyLinkLogo.png" alt="HarmonyLinkLogo"/>
</p>

Welcome to the server-side application for the HarmonyLink project. This innovative software is developed with the Rust programming language and is aimed at enhancing the handheld gaming experience.

## The Vision and The Reality

The central goal with HarmonyLink is to provide a comprehensive and interactive gaming experience on handheld devices. This client-side application is a crucial part of this vision.

## Key Features

1. **Device Identification**: HarmonyLink equips games with the ability to identify the specific handheld device they are operating on.
2. **Real-Time Metrics**: Games can access real-time data about the handheld device's power usage and docking status through HarmonyLink.
3. **Cross-Platform Compatibility**: HarmonyLink extends its functionality to Windows games running on Proton/Wine.

## How It Works

HarmonyLink operates using a client-server structure. This server-side application runs on the host side (native Linux or Windows), and games access the metrics via an API.

Developers and modders can easily implement GET and POST requests from the API, integrating system metrics into games. These metrics can be used to adapt the game's quality settings, providing a more customized gaming experience.

## Getting Started
### Prerequisites
Before getting started, make sure you have:

- A working installation of [Rust](https://www.rust-lang.org).
- Familiarity with Rust syntax and concepts.
- [Git](https://git-scm.com/downloads) installed on your system.

### Compiling
1. Clone the repository: `git clone https://github.com/Jordonbc/HarmonyLinkServer.git`
2. Navigate into the directory: `cd HarmonyLinkServer`
3. Build the project: `cargo build`
4. Run the project: `cargo run`

## HarmonyLink: View

To view the API in action, check out [HarmonyLink: View](https://github.com/Jordonbc/HarmonyLinkView). This sister project provides a comprehensive interface to see what data the API is providing.

## Showcasing HarmonyLink

👇 To help visualize its functionality, we've included a demonstration video that showcases HarmonyLink in action on a Steam Deck in gamemode. [![HarmonyLink in action](https://img.youtube.com/vi/qU3w_fo4nY4/0.jpg)](https://www.youtube.com/watch?v=qU3w_fo4nY4)

## Conclusion

HarmonyLink is a significant step towards revolutionizing the handheld gaming experience. Whether you're a game developer aiming to optimize your games for handheld devices or a gamer seeking a more personalized handheld gaming experience, HarmonyLink might just be what you've been waiting for.

We welcome your feedback, questions, and suggestions. Feel free to raise an issue or submit a pull request. Happy coding and game on!

## License

This project is licensed under the GNU General Public License v3.0 or later.
