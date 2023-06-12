use serde::Deserialize;
use std::env;
use std::error::Error;
use rand::seq::SliceRandom;
use std::io::Read;
use webbrowser;

pub type DiigoItems = Vec<DiigoItem>;

#[derive(Deserialize)]
pub struct DiigoItem {
    tags: String,
    readlater: String,
    annotations: Vec<String>,
    comments: Vec<String>,
    user: String,
    url: String,
    shared: String,
    created_at: String,
    desc: String,
    updated_at: String,
    title: String,
}

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

fn prompt_open(item: &DiigoItem) -> bool {
    println!("Open {}? [y/n/?]", item.url);
    let mut choice = String::new();
    std::io::stdin().read_line(&mut choice).unwrap();
    match choice.trim() {
        "y" => {
            webbrowser::open(&item.url).unwrap();
            return true;
        }
        "n" => return true,
        "?" => {
            println!("title: {}", item.title);
            println!("tags:  {}", item.tags);
        },
        _ => println!("unknown option '{}'", choice.trim()),
    }

    return false
}

fn main() -> Result<(), Box<dyn Error>> {
    let client = reqwest::blocking::Client::new();
    let user = env::var("DIIGO_USER")?;
    let pass = env::var("DIIGO_PASS")?;
    let api_key = env::var("DIIGO_API_KEY")?;
    let tag = env::var("DIIGO_SEARCH_TAG")?;

    println!("[Tags]");
    println!("1. readqueue");
    println!("2. read1queue");
    println!("3. twitterqueue");
    println!("4. blogqueue");
    println!("5. other");

    // TODO: loop through all available tags
    let url = format!("https://secure.diigo.com/api/v2/bookmarks?key={}&user={}&filter=all&tags={}&start=1&count=100", api_key, user, tag);
    // https://users.rust-lang.org/t/does-serde-not-consider-to-be-valid-json/28046/4
    // https://stackoverflow.com/questions/48595735/invalid-type-map-expected-a-sequence-when-deserializing-a-nested-json-struct - similar problem
    // https://old.reddit.com/r/rust/comments/792xk6/rust_beginner_help_parsing_json/ - parsing json with request
    // https://users.rust-lang.org/t/problems-at-turning-json-to-struct/30205/7 - generator for json types
    let resp = client.get(url)
          .basic_auth(user, Some(pass))
          .send()?
          .text()?;

    let items: DiigoItems = serde_json::from_str(&resp).unwrap();
    let mut item = items.choose(&mut rand::thread_rng()).unwrap();
    loop {
        if prompt_open(&item) {
            item = items.choose(&mut rand::thread_rng()).unwrap();
        }
    }

    println!("Hello, world!");

    Ok(())
}
