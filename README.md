# HarmonyLink: Client

Welcome to the client-side application for the HarmonyLink project. This innovative software is developed with the Rust programming language and is aimed at enhancing the handheld gaming experience. The main function of this client is to run the DLL which is currently closed-source.

## License

This project is licensed under the GNU General Public License v3.0 or later.

## The Vision and The Reality

The central goal with HarmonyLink is to provide a comprehensive and interactive gaming experience on handheld devices. This client-side application is a crucial part of this vision.

## Key Features

1. **Device Identification**: HarmonyLink equips games with the ability to identify the specific handheld device they are operating on.
2. **Real-Time Metrics**: Games can access real-time data about the handheld device's power usage and docking status through HarmonyLink.
3. **Cross-Platform Compatibility**: HarmonyLink extends its functionality to Windows games running on Proton/Wine.

## How It Works

HarmonyLink operates using a client-server structure. This client-side application runs the DLL on the host side (native Linux or Windows), and games access the metrics via an API.

Developers and modders can easily implement GET and POST requests from the API, integrating system metrics into games. These metrics can be used to adapt the game's quality settings, providing a more customized gaming experience.

## Getting Started

1. Clone the repository: `git clone https://github.com/Jordonbc/HarmonyLinkClient.git`
2. Navigate into the directory: `cd HarmonyLinkClient`
3. Build the project: `cargo build`
4. Run the project: `cargo run`

Please note that while the DLL is currently closed-source, we're open to making it open-source if it gains popularity. We're excited to see how the project evolves with community engagement.

## HarmonyLink: View

To view the API in action, check out [HarmonyLink: View](https://github.com/Jordonbc/HarmonyLinkView). This sister project provides a comprehensive interface to see what the API is doing in real-time.

## Showcasing HarmonyLink

To help visualize its functionality, we've included a demonstration video that showcases HarmonyLink in action on a Steam Deck in desktop mode. (Insert link to video here)

## Conclusion

HarmonyLink is a significant step towards revolutionizing the handheld gaming experience. Whether you're a game developer aiming to optimize your games for handheld devices or a gamer seeking a more personalized handheld gaming experience, HarmonyLink might just be what you've been waiting for.

We welcome your feedback, questions, and suggestions. Feel free to raise an issue or submit a pull request. Happy coding and game on!
